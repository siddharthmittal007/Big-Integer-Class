#include "definition.h"

string BIGINT::add(string s1, string s2){
    int carry=0,i,j;
    int sum = 0;
    int x = s1.length();
    int y = s2.length();
    string answer = "";
    if(x==0 and y==0){
        answer = "0";
    }
    else if(s1[0]=='-' and s2[0]=='-'){
        answer = add(s1.erase(0,1),s2.erase(0,1));
        answer = '-'+answer;
    }
    else if(s1[0]=='-'){
        answer = subtract(s2,s1.erase(0,1));
    }
    else if(s2[0]=='-'){
        answer = subtract(s1,s2.erase(0,1));
    }
    else{
        vector<int> v;
        for(i=x-1,j=y-1; i>=0 or j>=0; i--,j--){
            sum = carry;
            if(i>=0){
                sum+=s1[i]-'0';
            }
            if(j>=0){
                sum+=s2[j]-'0';
            }
            v.push_back(sum%10);
            carry = sum/10;
        }
        if(carry!=0)
            v.push_back(carry);
        for(i=v.size()-1; i>=0; i--){
            answer+=(char)(v[i]+48);
        }
    }
    // answer = remove_0_front(answer);
    return answer;
}

string BIGINT::subtract(string s1, string s2){
    string answer = "", ans, temp;
    int carry=0, p=0, i, j, k, flag1=0, flag2=0;
    int sum=0;
    if(s1==s2){
        return "0";
    }
    else if(s1[0]=='-' and s2[0]=='-'){
        flag2 = 1;
        s1 = s1.erase(0,1);
        s2 = s2.erase(0,1);
        // cout<<"///"<<s1<<"////"<<s2<<"////"<<endl;
    }
    else if(s1[0]=='-' and s2[0]!='-'){
        s1 = s1.erase(0,1);
        answer = add(s1,s2);
        answer = '-'+answer;
        return answer;
    }
    else if(s1[0]!='-' and s2[0]=='-'){
        s2 = s2.erase(0,1);
        answer = add(s1,s2);
        return answer;
    }
    ans = maxCompare(s1,s2);
    if(ans==s2){
        temp = s1;
        s1=s2;
        s2=temp;
        flag1=1;
    }
    int x = s1.length();
    int y = s2.length();
    if(x>y)
        k=x;
    else
        k=y;
    int A[k+1];
    memset(A, 0, (k+1)*sizeof(int));
    for(i=x-1,j=y-1; i>=0 or j>=0; i--,j--){
        sum=0;
        if(i>=0){
            sum+=s1[i]-'0';
        }   
        if(j>=0){
            if(sum<s2[j]-'0'+carry){
                sum+=10;
                sum-=s2[j]-'0'+carry;
                carry = 1;
            }            
            else{
                sum-=s2[j]-'0'+carry;
                carry=0;
            }            
        }
        if(carry!=0 and j<0){
            if(sum<carry){
                sum+=10;
                sum-=carry;
                carry=1;
            }
            else{
                sum-=carry;
                carry=0;
            }
        }
        A[p++]=sum;
    }
    for(i=k-1; i>=0; i--){
        answer += (char)(A[i]+48);
    }
    // answer=remove_0_front(answer);
    if(flag2==1 and flag1==0){
        answer='-'+answer;
    }
    else if(flag2==0 and flag1==1){
        answer='-'+answer;
    }
    // answer = remove_0_front(answer);
    return answer;
}

string BIGINT::multiply(string s1, string s2){
    if(s1=="0" or s2=="0"){
        return "0";
    }
    else if(s1=="1"){
        return s2;
    }
    else if(s2=="1"){
        return s1;
    }
    int flag=0;
    int x = s1.length();
    int y = s2.length();
    int A[x+y];
    memset(A, 0, (x+y)*sizeof(int));
    for(int i=x-1; i>=0; i--){
        for(int j=y-1; j>=0; j--){
            int mul = (s1[i]-'0')*(s2[j]-'0');
            int sum = A[i+j+1]+mul;
            A[i+j]+=sum/10;
            A[i+j+1]=sum%10;
        }
    }
    string answer = "";
    for(int i=0; i<x+y; i++){
        if(A[i]==0 and flag==0){
            continue;
        }
        else if(A[i]!=0){
            flag=1;
        }
        if(flag==1){
            answer+=(char)(A[i]+48);
        }
    }
    answer = remove_0_front(answer);
    return answer;
}

string BIGINT::division(string s1, long long int n){
    string answer;
    int index = 0;
    long long int temp = s1[index] - '0';
    while(temp<n){
        temp = temp*10 + (s1[++index]-'0');
        if(index>=s1.length())
            break;
    }
    while(s1.length() > index){
        answer+=(temp/n)+'0';
        temp = (temp%n)*10 + s1[++index]-'0';
    }
    if(answer.length()==0){
        return "0";
    }
    answer = remove_0_front(answer);
    return answer;
}

string BIGINT::factorial(int n){
    string s;
    BIGINT A("1");
    for(int i=1; i<=n; i++){
        A = A*i;
    }
    return A.str;
}

//default constructor
BIGINT::BIGINT(){
    str = "0";
}

BIGINT::BIGINT(string s){
    if(!inputVerification(s)){
        cerr<<"Invalid Input"<<endl;
        exit(0);
    }
    str = s;
}

BIGINT::BIGINT(long long int n){
    ostringstream convert;
    convert<<n;
    str = convert.str();
}

BIGINT::BIGINT(const BIGINT &N){
    if(!inputVerification(N.str)){
        cerr<<"Invalid Input"<<endl;       
        exit(0);
    }
    str = N.str;
}

//verification of argument string 
bool BIGINT::inputVerification(string s){
    if(s[0]=='-'){
        s.erase(0,1);
    }
    for(int i=0; i<s.length(); i++){
        if((int)s[i]<48 or (int)s[i]>57){
            return false;
        }
    }
    return true;
}
//overloading <<
ostream &operator<<(ostream &output, const BIGINT &N){
    output<<N.str;
    return output;
}
//overloading >>
istream &operator>>(istream &input, BIGINT &N){
    input>>N.str;
    return input;
}

BIGINT BIGINT::to_BIGINT(string s){
    BIGINT N;
    N.str = s;
    return N;
}

BIGINT BIGINT::to_BIGINT(long long int n){
    BIGINT N;
    ostringstream convert;
    convert<<n;
    N.str = convert.str();
    return N; 
}

string BIGINT::remove_0_front(string s){
    int i=0, flag=0;    
    if(s[0]=='-'){
        flag=1;
        i++;
    }
    while(s[i]=='0'){
        i++;
    }
    if(flag)
        s.erase(1,i);
    else
        s.erase(0,i);
    return s;
}


BIGINT BIGINT::operator++(){  //pre increment
    string s = "1";
    str = add(this->str,s);
    return *this;
}

BIGINT BIGINT::operator--(){   //pre increment
    string s = "1";
    str = subtract(this->str,s);
    return *this;
}

BIGINT BIGINT::operator++(int){  //post increment
    string s = "1";
    str = add(str,s);
    return *this;

    // BIGINT N;
    // N.str = this->str;
    // string s = "1";
    // str = add(this->str,s);
    // return N;
}

BIGINT BIGINT::operator--(int){  //post increment
    string s = "1";
    str = subtract(this->str,s);
    return *this;
    // BIGINT N;
    // N.str = this->str;
    // string s = "1";
    // str = subtract(this->str,s);
    // return N;
}

BIGINT BIGINT::operator+(BIGINT const &N){
    BIGINT N2;
    N2.str = add(str,N.str);
    return N2;
}

BIGINT BIGINT::operator-(BIGINT const &N){
    BIGINT N2;
    N2.str = subtract(str,N.str);
    return N2;
}

BIGINT BIGINT::operator*(BIGINT const &N){
    BIGINT N2;
    N2.str = multiply(str,N.str);
    return N2;
}

BIGINT BIGINT::operator/(BIGINT const &N){
    BIGINT N2;
    string temp = N.str;
    stringstream convert(temp);
    long long int n = 0;
    convert>>n;
    N2.str = division(str,n);
    return N2;
}

bool BIGINT::operator==(BIGINT const &N){
    return this->str==N.str;
}

bool BIGINT::operator!=(BIGINT const &N){
    return this->str!=N.str;
}

//for adding BIGINT and integer
BIGINT operator+(BIGINT &N,int n){
    BIGINT N2;
    ostringstream convert;
    convert<<n;
    N2.str = convert.str();
    N2.str = BIGINT::add(N.str,N2.str);
    return N2;
}

//for subtracting BIGINT and integer
BIGINT operator-(BIGINT &N,int n){
    BIGINT N2;
    ostringstream convert;
    convert<<n;
    N2.str = convert.str();
    N2.str = BIGINT::subtract(N.str,N2.str);
    return N2;
}

//for product of BIGINT and integer
BIGINT operator*(BIGINT &N,int n){
    BIGINT N2;
    ostringstream convert;
    convert<<n;
    N2.str = convert.str();
    N2.str = BIGINT::multiply(N.str,N2.str);
    return N2;
}

//for division BIGINT and integer
BIGINT operator/(BIGINT &N,int n){
    BIGINT N2;
    N2.str = BIGINT::division(N.str,(long long int)n);
    return N2;
}

// for adding integer and BIGINT
BIGINT operator+(int n, BIGINT &N){
    BIGINT N2;
    ostringstream convert;
    convert<<n;
    N2.str = convert.str();
    N2.str = BIGINT::add(N.str,N2.str);
    return N2;    
}

// for subtracting integer and BIGINT
BIGINT operator-(int n, BIGINT &N){
    BIGINT N2;
    ostringstream convert;
    convert<<n;
    N2.str = convert.str();
    N2.str = BIGINT::subtract(N.str,N2.str);
    return N2;
}

// for product of integer and BIGINT
BIGINT operator*(int n, BIGINT &N){
    BIGINT N2;
    ostringstream convert;
    convert<<n;
    N2.str = convert.str();
    N2.str = BIGINT::multiply(N.str,N2.str);
    return N2;
}

// for division of integer and BIGINT
BIGINT operator/(int n, BIGINT &N){
    BIGINT N2;
    N2.str = BIGINT::division(N.str,(long long int)n);
    return N2;
}


BIGINT BIGINT::factBIGINT(BIGINT N){
    BIGINT N2;
    string s = N.str;
    stringstream convert(s);
    int n = 0;
    convert>>n;
    N2.str = factorial(n);
    return N2;
}

BIGINT BIGINT::factBIGINT(string s){
    BIGINT N2;
    stringstream convert(s);
    int n = 0;
    convert>>n;
    N2.str = factorial(n);
    return N2;
}

BIGINT BIGINT::factBIGINT(int n){
    BIGINT N2;
    N2.str = factorial(n);
    return N2;
}


string BIGINT::maxCompare(string s1, string s2){
    string answer = "";
    int i;
    if(s1[0]=='-' and s2[0]!='-'){
        return s2;
    }
    else if(s1[0]!='-' and s2[0]=='-'){
        return s1;   
    }
    else if(s1[0]!='-' and s2[0]!='-' and s1.length()>s2.length()){
        return s1;
       }
    else if(s1[0]!='-' and s2[0]!='-' and s1.length()<s2.length()){
        return s2;
    }
    else if(s1[0]=='-' and s2[0]=='-' and s1.length()>s2.length()){
        return s2;
    }
    else if(s1[0]=='-' and s2[0]=='-' and s1.length()<s2.length()){
        return s1;
    }
    else if(s1[0]!='-' and s2[0]!='-' and s1.length()==s2.length()){
        for(int i=0; i<s1.length(); i++){
            if(s1[i]-'0'<s2[i]-'0'){
                return s2;
            }
            else if(s1[i]==s2[i]){
                continue;
            }
            else if(s1[i]-'0'>s2[i]-'0'){
                return s1;
            }
        }
    }
    else if(s1[0]=='-' and s2[0]=='-' and s1.length()==s2.length()){
        for(int i=0; i<s1.length(); i++){
            if(s1[i]-'0'<s2[i]-'0'){
                return s1;
            }
            else if(s1[i]==s2[i]){
                continue;
            }
            else if(s1[i]-'0'>s2[i]-'0'){
                return s2;
            }
        }   
    }
    return "0";
}

string BIGINT::minCompare(string s1, string s2){
    string answer;
    answer = maxCompare(s1,s2);
    if(answer==s1){
        return s2;
    }
    else{
        return s1;
    }
}

BIGINT BIGINT::maxBIGINT(BIGINT N1, BIGINT N2){
    string answer = maxCompare(N1.str,N2.str);
    if(N1.str==answer){
        return N1;
    }
    else{
        return N2;
    }    
}

BIGINT BIGINT::minBIGINT(BIGINT N1, BIGINT N2){
    string answer = minCompare(N1.str,N2.str);
    if(N1.str==answer){
        return N1;
    }
    else{
        return N2;
    }
}

BIGINT BIGINT::absBIGINT(BIGINT N){
    string s = N.str;
    if(s[0]=='-'){
        s = s.substr(1);
    }
    BIGINT N2(s);
    return N2;
}
