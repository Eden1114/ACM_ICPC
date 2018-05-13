/*
 *题号：Codeforces 544C
 *时间：2018年05月10日19:30:52
 *解题思想：完全背包
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

const double eps=1e-8,pi=acos(1.0*(-1));
//const int INF=0x3f3f3f3f,mod=1e9+7;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef std::pair<int,int> P;
typedef long long LL;
typedef long long ll;
using namespace std;

const long long maxn = 500 + 10;
const long long maxm = 500 + 10;
long long m, n, b, mod;
long long a[maxn];
long long dp[maxm][maxn];

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n >> m >> b >> mod;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        //dp[1][a[i]]++;
    }
    
    dp[0][0] = 1;
    
    for(int i = 1; i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int k = a[i];k <= b;k++) {
                dp[j][k] += dp[j-1][k-a[i]];
                dp[j][k] %= mod;
            }
        }
    }
    
//    for(int i = 1;i <= n;i++)  
//    {  
//        for(int j = 1;j <= m;j++) 
//        {  
//            for(int k = a[i]; k <= b;k++)
//            {  
//                dp[j][k] += dp[k-1][j-a[k]];  
//                dp[j][k] %= mod;
//            }  
//        }  
//    }  
    
    
    long long ans = 0;  
    for(int i = 0;i <= b; i++) {  
        ans=(ans + dp[m][i]) % mod;  
    }
    cout << ans << endl;
    return 0;
}