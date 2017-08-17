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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <cstring>
#include <climits>
#include <limits>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

#define F(i,a,b) for(int i = a; i < b; i++)
#define LL long long
#define rei(x) scanf("%d",&x)
#define rel(x) scanf("%I64d",&x)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define f(i, a, b) for(int i = a; i <= b; i++)
#define ms(Arr) memset(Arr,0,sizeof(Arr));
#define CLR(arr,val)  memset(arr,val,sizeof(arr))

const double eps = 1e-8;
const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;

//最大公因数
long long gcd(long long a, long long b)
{ 
    return b == 0 ? a : gcd(b, a%b);
} 
//利用了恒等式:gcd(a,b) == gcd(b,a mod b)

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}


//快速幂取模
int PowerMod(int a, int b, int c)

{

    int ans = 1;

    a = a % c;

    while (b > 0)

    {

        if (b % 2 == 1)

            ans = (ans * a) % c;

        b = b / 2;

        a = (a * a) % c;

    }

    return ans;

}

//幂函数
int p(int a, int b)
{
    int ans = 1;
    for (int i = 0; i < b; i++)
        ans *= a;
    return ans;
}

const int dx[9] = { 0,1,-1,0,0,-1,-1,1,1 };
const int dy[9] = { 0,0,0,-1,1,-1,1,-1,1 };

int Scan()
{   //  输入外挂  
    int res = 0, flag = 0;
    char ch;
    if ((ch = getchar()) == '-')
    {
        flag = 1;
    }
    else if (ch >= '0' && ch <= '9')
    {
        res = ch - '0';
    }
    while ((ch = getchar()) >= '0' && ch <= '9')
    {
        res = res * 10 + (ch - '0');
    }
    return flag ? -res : res;
}

void Out(int a)
{   //  输出外挂  
    if (a < 0)
    {
        putchar('-');
        a = -a;
    }
    if (a >= 10)
    {
        Out(a / 10);
    }
    putchar(a % 10 + '0');
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//long long 范围：-9223372036854775808~9223372036854775807
//int 范围：-2147483648~2147483647
//double 范围：-1.7*10^-308~1.7*10^308，15~16位有效数字
//long double 范围：-1.2*10^-4932~1.2*10^4932，18~19位有效数字
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(/*int argc, char *argv[]*/) {
    //ios::sync_with_stdio(false);
    long long n,a,b,p,q;
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&p,&q);
    long long t1,t2,t3,res;
    t1 = n / a;
    t2 = n / b;
    t3 = n / lcm(a,b);
    //cout<<t1<<endl;
    //cout<<t2<<endl;
    //cout<<t3<<endl;
    if(p > q)
    {
        res = p * t1 + q * (t2 - t3);
    }
    else
    {
        res = q * t2 + p * (t1 - t3);
    }
    cout<<res<<endl;
    return 0;
}