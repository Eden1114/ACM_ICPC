/*
 *题号：
 *时间：
 *解题思想：0-1背包 + 完全背包
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
const int maxn = 2e3 + 7;
int m,n,check[maxn],res[maxn],dp[maxn];

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int T;
    cin>>T;
    while(T--)
    {
        cin>>m>>n;//money
        memset(dp, 0, sizeof(dp));
        int a,b,cost;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d%d", &cost, &a, &b);
            memset(check, 0, sizeof(check));
            for(int i = 0; i <= m;i++)
            {
                res[i] = dp[i];
            }
            //把dp[i]复制到res[i]中
            
            for(int i = cost; i <= m;i++)
            {
                if(res[i-cost] + a + b >= dp[i])
                    check[i] = 1;
                res[i] = max(res[i-cost] + a,res[i]);
            }
            //
            
            for(int i = m;i >= 0;i--)
                if (check[i] == 1) 
                    res[i] = max(res[i],res[i-cost] + a + b);
            
            for(int i = 0; i <= m;i++)
            {
                dp[i] = max(dp[i],res[i]);
            }
        }
        int ans = 0;
        for(int i = 0;i <= m;i++)
        {
            ans = max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
	return 0;
}