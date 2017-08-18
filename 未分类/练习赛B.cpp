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
const int maxn = 15 + 5;
const int maxm = 100 + 5;

int m,n;

char s[maxn][maxm];
int room[maxn][2];
bool light[maxn];

#define _left 0
#define _right 1

int dp[maxn][2];


void dfs()
{
    //第一层特别处理
    
    if(light[n-1])
    {
        dp[n-1][_left] = 2 * room[n-1][_right];
        dp[n-1][_right] = m + 1;
    }
    else
    {
        dp[n-1][_left] = 0;
        dp[n-1][_right] = m + 1;
    }
    
    for(int i = n - 2;i >= 1;i--)
    {
        if(light[i])
        {
            dp[i][_left] = min(dp[i+1][_left] + 2 * room[i][_right], dp[i+1][_right] + m + 1) + 1;
            dp[i][_right] = min(dp[i+1][_left] + m + 1, dp[i+1][_right] + 2 * (m + 1 -room[i][_left])) + 1;
        }
        else
        {
            dp[i][_left] = dp[i+1][_left] + 1;
            dp[i][_right] = dp[i+1][_right] + 1;
        }
    }
}

int main(/*int argc, char *argv[]*/) {
    //ios::sync_with_stdio(false);
    cin>>n>>m;
    
    memset(light,true, sizeof(light));
    
    for(int i = 0;i < n;i++)
    {
        scanf("%s",s[i]);
        int j,k;
        for(k = 0;k <= m + 1;k++)
            if(s[i][k] == '1')
            {
                room[i][_left] = k;
                break;
            }
        
        for (j = m + 1;j >= 0;j--)
        {
            if(s[i][j] == '1')
            {
                room[i][_right] = j;
                break;
            }
        }
        
        if (k == m + 2 && j == -1)
        {
            light[i] = false;
        }
    }
    dfs();
    
    int i = 0;
    while(!light[i]) i++;
    if(i < n - 1)
    {
        int res = min(dp[i+1][_left] + room[i][_right],
                  dp[i+1][_right] + m + 1 - room[i][_left]) + 1;
        cout<<res<<endl;
    }
    else if (i == n - 1){
        if(light[i])
            cout<<room[i][_right]<<endl;
        else
            cout<<0<<endl;
    }
    else if(i > n - 1)
        cout<<0<<endl;
    return 0;
}