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
const int maxn = 1024+5;
int area[maxn][maxn];
int n;
inline int lowbit(int x) {
    return x& (-x);
}

inline void insert(int x,int y,int k)
{
    for(int i = x; i <= n; i += lowbit(i))
        for(int j = y; j <= n; j += lowbit(j))
            area[i][j] += k;
}

inline int query(int x,int y) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
    {
        for(int j = y; j; j-= lowbit(j))
        {
            ans += area[i][j];
        }
    }
    return ans;
}

int main(/*int argc, char *argv[]*/) {
    //ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);
    memset(area, 0, sizeof(area));
    cin >> n;
    while(true)
    {
        int op;
        cin>>op;
        if(op == 1) {
            int x,y,k;
            cin>>x>>y>>k;
            insert(x+1, y+1, k);
        }
        else if(op == 2) {
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout<<query(x2+1,y2+1)-query(x1,y2+1)-query(x2+1,y1)+query(x1,y1)<<endl;
        }
        else if(op == 3) {
            break;
        }
    }
    return 0;
}