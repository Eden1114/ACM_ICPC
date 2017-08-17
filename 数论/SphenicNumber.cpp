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
int gcd(int a, int b)
{
    if (!b)return a;
    return gcd(b, a%b);
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
const int maxn = 100249;
long long isprime[maxn];
long long prime[maxn];
long long res[maxn];
int idx = 0;

void prime_list()
{
    int i,j;
    memset(isprime, 0, sizeof isprime);
    for(i = 2; i < maxn; i++)
    {
        if(isprime[i] == 0)
        {
            prime[idx++] = i;
            for(j = i + i;j < maxn; j+= i)
            {
                isprime[j] = 1;
            }
        }
    }
}


int main()
{
    //
    prime_list();
    //cout<<idx<<endl;
    int i,j,k,t;
    t = 0;
    for(i = 0; i < idx; i++)
    {
        for(j = i + 1; j < idx; j++)
        {
            for(k = j + 1; k < idx; k++)
            {
                long long temp = prime[i] * prime[j] * prime[k];
                if(temp > 488000) break;
                else
                    res[t++] = temp;
            }
        }
    }
    sort(res,res+t);
    int T;
    scanf("%d",&T);
    for(i = 0; i < T; i++)
    {
        scanf("%d",&j);
        printf("%lld\n",res[j-1]);
    }
    
    return 0;
}