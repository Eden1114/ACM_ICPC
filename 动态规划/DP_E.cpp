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
const int maxn = 1e4 + 5;
int a[maxn];
int dp[maxn];

int st[maxn];
int ed[maxn];

int main(){
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0;i < n;i++) scanf("%d",&a[i]);
        dp[0] = a[0];
        st[0] = 0;
        ed[0] = 0;
        for(int i = 1;i < n;i++) 
        {
            if(dp[i-1] < 0) 
            {
                dp[i] = a[i];
                st[i] = i;
                ed[i] = i;
            }
            else
            {
                dp[i] = a[i] + dp[i-1];
                st[i] = st[i-1];
                ed[i] = i;
            }
        }
        int m = -INF;
        for(int i = 0;i < n;i++)
            m = max(m,dp[i]);
        
        for(int i = 0;i < n;i++)
        {
            if(dp[i] == m)
            {
                if(m >= 0)
                {
                    printf("%d %d %d\n",dp[i],a[st[i]],a[ed[i]]);
                    break;
                }
                else
                {
                    printf("0 %d %d\n",a[0],a[n-1]);
                    break;
                }
            }
            
        }
    }
    return 0;
}