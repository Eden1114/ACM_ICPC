/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

#define F(i,a,b) for(int i = a; i < b; i++)


const double eps = 1e-8;
const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;

#define MAXN 9999  
#define MAXSIZE 10  
#define DLEN 4  
  
class BigNum  
{   
public:    
    int a[500];    //可以控制大数的位数   
    int len;       //大数长度  
public:   
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //构造函数  
    BigNum(const char*);     //将一个字符串类型的变量转化为大数
    BigNum(const BigNum &);  //拷贝构造函数  
      
    friend istream& operator>>(istream&,  BigNum&);   //重载输入运算符  
        
    BigNum operator/(const int   &) const;    //重载除法运算符，大数对一个整数进行相除运算  
         
    bool   operator>(const BigNum & T)const;   //大数和另一个大数的大小比较  
    bool   operator>(const int & t)const;      //大数和一个int类型的变量的大小比较  
      
};   

BigNum::BigNum(const char*s)     //将一个字符串类型的变量转化为大数  
{  
    int t,k,index,l,i;  
    memset(a,0,sizeof(a));  
    l=strlen(s);     
    len=l/DLEN;  
    if(l%DLEN)  
        len++;  
    index=0;  
    for(i=l-1;i>=0;i-=DLEN)  
    {  
        t=0;  
        k=i-DLEN+1;  
        if(k<0)  
            k=0;  
        for(int j=k;j<=i;j++)  
            t=t*10+s[j]-'0';  
        a[index++]=t;  
    }  
}  
BigNum::BigNum(const BigNum & T) : len(T.len)  //拷贝构造函数  
{   
    int i;   
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)  
        a[i] = T.a[i];   
}   

istream& operator>>(istream & in,  BigNum & b)   //重载输入运算符  
{  
    char ch[MAXSIZE*4];  
    int i = -1;  
    in>>ch;  
    int l=strlen(ch);  
    int count=0,sum=0;  
    for(i=l-1;i>=0;)  
    {  
        sum = 0;  
        int t=1;  
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)  
        {  
            sum+=(ch[i]-'0')*t;  
        }  
        b.a[count]=sum;  
        count++;  
    }  
    b.len =count++;  
    return in;  
      
} 

 
BigNum BigNum::operator/(const int & b) const   //大数对一个整数进行相除运算  
{   
    BigNum ret;   
    int i,down = 0;     
    for(i = len - 1 ; i >= 0 ; i--)  
    {   
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;   
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;   
    }   
    ret.len = len;   
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)  
        ret.len--;   
    return ret;   
}  


bool BigNum::operator>(const BigNum & T) const   //大数和另一个大数的大小比较  
{   
    int ln;   
    if(len > T.len)  
        return true;   
    else if(len == T.len)  
    {   
        ln = len - 1;   
        while(a[ln] == T.a[ln] && ln >= 0)  
            ln--;   
        if(ln >= 0 && a[ln] > T.a[ln])  
            return true;   
        else  
            return false;   
    }   
    else  
        return false;   
}  
bool BigNum::operator >(const int & t) const    //大数和一个int类型的变量的大小比较  
{  
    BigNum b(t);  
    return *this>b;  
}  

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	string a;
    int b;
    cin>>a>>b;
    B
    while(b)
    {
        
        b--;
    }
    
    if(a <= 1)
    cout<<"Your wish is granted!"<<endl;
    else
    {
        cout<<"You will become a flying monkey!"<<endl;
    }
	return 0;
}