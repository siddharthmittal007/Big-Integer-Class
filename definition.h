#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class INTAL{
    private:
        string str;
        static string add(string s1, string s2);
        static string subtract(string s1, string s2);
        static string multiply(string s1, string s2);
        static string division(string s1, long long int n);
        static string factorial(int n);
    public:

        INTAL();
        INTAL(string s);
        INTAL(long long int n);
        INTAL(const INTAL &N);

        bool inputVerification(string s);

        friend ostream &operator<<(ostream &output, const INTAL &N);
        friend istream &operator>>(istream &input, INTAL &N);

        static INTAL to_INTAL(string s);
        static INTAL to_INTAL(long long int n);
        static string remove_0_front(string s);
        
        INTAL operator++();
        INTAL operator--();
        INTAL operator++(int);
        INTAL operator--(int);
        INTAL operator+(INTAL const &N);
        INTAL operator-(INTAL const &N);
        INTAL operator*(INTAL const &N);
        INTAL operator/(INTAL const &N);
        bool operator==(INTAL const &N);
        bool operator!=(INTAL const &N);

        friend INTAL operator+(INTAL &N,int n);
        friend INTAL operator-(INTAL &N,int n);
        friend INTAL operator*(INTAL &N,int n);
        friend INTAL operator/(INTAL &N,int n);
        friend INTAL operator+(int n, INTAL &N);
        friend INTAL operator-(int n, INTAL &N);
        friend INTAL operator*(int n, INTAL &N);
        friend INTAL operator/(int n, INTAL &N);
        
        static INTAL factINTAL(INTAL N);
        static INTAL factINTAL(string s);
        static INTAL factINTAL(int n);
        
        static string maxCompare(string s1, string s2);
        static string minCompare(string s1, string s2);

        static INTAL maxINTAL(INTAL N1, INTAL N2);
        static INTAL minINTAL(INTAL N1, INTAL N2);    
        static INTAL absINTAL(INTAL N);
};  
