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
const int maxn = 1e5 + 5;
int a[maxn];
int dp[maxn];
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int n;cin>>n;
    for(int i = 0;i  < n;i++)
    {
        cin>>a[i];
    }
    int max_minus_odd = -INF;
    int min_positive_odd = INF; 
    for(int i = 0 ;i < n;i++)
    {
        if(a[i] < 0) 
        {
            dp[i] = dp[i-1];
            if(a[i] & 1 && a[i] < 0)
            {
                max_minus_odd = max(max_minus_odd,a[i]);
            }
        }
        else 
        {
            dp[i] = dp[i-1] + a[i];
            if(a[i] > 0 && a[i] & 1)
            {
                min_positive_odd = min(min_positive_odd,a[i]);
            }
        }
    }
    
    if(dp[n-1] & 1)
    {
        cout<<dp[n-1]<<endl;
    }
    else 
    {
        cout << max( dp[n-1] + max_minus_odd, dp[n-1]-min_positive_odd)<<endl;
    }
    
	return 0;
}