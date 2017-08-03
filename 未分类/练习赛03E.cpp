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
string s,t;
const int maxn = 1e3 + 5;
int dp[maxn][maxn];
int n,m;
void solve(){
    n = s.length();
    m = t.length();
    memset(dp, 0, sizeof(dp));
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(s[i] == t[j])
            {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
            else 
            {
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
}


int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	while(cin>>s>>t)
    {
        solve();
        cout<<dp[n][m]<<endl;
    }
	return 0;
}