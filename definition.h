#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class BIGINT {
    private:
        string str;
        static string add(string s1, string s2);
        static string subtract(string s1, string s2);
        static string multiply(string s1, string s2);
        static string division(string s1, long long int n);
        static string factorial(int n);
    public:

        BIGINT();
        BIGINT(string s);
        BIGINT(long long int n);
        BIGINT(const BIGINT &N);

        bool inputVerification(string s);

        friend ostream &operator<<(ostream &output, const BIGINT &N);
        friend istream &operator>>(istream &input, BIGINT &N);

        static BIGINT to_BIGINT(string s);
        static BIGINT to_BIGINT(long long int n);
        static string remove_0_front(string s);
        
        BIGINT operator++();
        BIGINT operator--();
        BIGINT operator++(int);
        BIGINT operator--(int);
        BIGINT operator+(BIGINT const &N);
        BIGINT operator-(BIGINT const &N);
        BIGINT operator*(BIGINT const &N);
        BIGINT operator/(BIGINT const &N);
        bool operator==(BIGINT const &N);
        bool operator!=(BIGINT const &N);

        friend BIGINT operator+(BIGINT &N,int n);
        friend BIGINT operator-(BIGINT &N,int n);
        friend BIGINT operator*(BIGINT &N,int n);
        friend BIGINT operator/(BIGINT &N,int n);
        friend BIGINT operator+(int n, BIGINT &N);
        friend BIGINT operator-(int n, INTAL &N);
        friend BIGINT operator*(int n, INTAL &N);
        friend BIGINT operator/(int n, INTAL &N);
        
        static BIGINT factINTAL(INTAL N);
        static BIGINT factINTAL(string s);
        static BIGINT factINTAL(int n);
        
        static string maxCompare(string s1, string s2);
        static string minCompare(string s1, string s2);

        static BIGINT maxINTAL(INTAL N1, INTAL N2);
        static BIGINT minINTAL(INTAL N1, INTAL N2);    
        static BIGINT absINTAL(INTAL N);
};  
