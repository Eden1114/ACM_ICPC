#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
#define F(n) for(int i = 0; i < n; i++)
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int a[110];
    int dp[110];
    memset(dp,0,sizeof(dp));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1; j <= i;j++)
        {
            cin>>a[j];
        }
        
        for(int j = 1; j <= i;j++)
        {
            if (j == 1) dp[j] = dp[j] + a[j];
            else if(j == i) dp[j] = dp[j-1] + a[j];
            else dp[j] = max(dp[j],dp[j-1])+a[j]; 
        }
        
        
        
    }
}