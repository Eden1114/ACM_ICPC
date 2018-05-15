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

#define rei(x) scanf("%d",&x)
#define rel(x) scanf("%I64d",&x)
#define fi first
#define se second
#define f(i, a, b) for(int i = a; i <= b; i++)
#define ms(Arr) memset(Arr,0,sizeof(Arr));
#define CLR(arr,val)  memset(arr,val,sizeof(arr))

const double eps=1e-8,pi=acos(1.0*(-1));
const int INF=0x3f3f3f3f,mod=1e9+7;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
typedef std::pair<int,int> P;
typedef long long LL;
typedef long long ll;
using namespace std;
ll gcd(ll a,ll b){if(a<b)swap(a,b);return b==0?a:gcd(b,a%b);}
ll lcm(ll a,ll b){if(a<b)swap(a,b);return a/gcd(a,b)*b;}
ll quickPow(ll a,ll b,ll c=mod){ll z=1;a=a%c;while(b>0){if(b&1)z=(z*a)%c;b=b>>1;a=(a*a)%c;}return z;}
int Scan(){int r=0,f=0;char c;if ((c=getchar())=='-')f=1;else if(c>='0'&&c<='9'){r=c-'0';}while((c=getchar()) >='0'&&c<='9'){r=r*10+(c-'0');}return f?-r:r;}
void Out(int a){if(a < 0){putchar('-');a = -a;}if (a >= 10){Out(a / 10);}putchar(a % 10 + '0');}

/////////////////////////////////////////////////////////////////////////
//long long 范围：-9223372036854775808 ~ 9223372036854775807
//int 范围：-2147483648 ~ 2147483647
//double 范围：-1.7*10^-308 ~ 1.7*10^308，15~16位有效数字
//long double 范围：-1.2*10^-4932 ~ 1.2*10^4932，18~19位有效数字
/////////////////////////////////////////////////////////////////////////
int x,y,cnt;
int r[200];
int d[200];
int tot;
int ind;
set<int> s;

int main() {
    scanf("%d%d",&x,&y);
    tot = 0;
    ind = 0;
    s.clear();
    
    if(x % y == 0) {
        cout<< x / y <<endl;
        return 0;
    }
    
    while(x != 0 && cnt <= 110)
    {
        int di = x / y;
        int re = x % y;
        d[ind] = di;
        r[ind] = re;
        ind++;
        if(s.count(re) == 0) s.insert(re);
        else {
            int i = ind;
            int nowre = (re * 10) % y;
            while(r[i] != nowre && i != 0) i--;
            printf("%d.",d[0]);
            
            for(int j = 1; j < i;j++)
                printf("%d",d[j]);
            
            putchar('(');
            for(int j = i;j < ind;j++)
                printf("%d",d[j]);
            putchar(')');
            return 0;
        }
        x = re * 10;
        cnt++;
        
//        for(int i = 0;i < ind;i++)
//        {
//            cout<< "d[]"<<d[i]<<"r[]"<<r[i]<<endl;
//        }
    }
    
    printf("%d.", d[0]);
    for(int i = 1;i <= 100;i++)
        printf("%d",d[i]);
    putchar('\n');
    return 0;
}
