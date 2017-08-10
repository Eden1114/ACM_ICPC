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
            
        for(j = m + 1;j >= 0;j--)
        {
            if(s[i][j] == '1')
            {
                room[i][_right] = j;
                break;
            } 
        }
        
        if(k == m + 1 && j == 0)
        {
            light[i] = false;
        }
    }
    
    
    for(int i = n - 1;i >= 0;i--)
    {
        if(i == n - 1)
        {
            if(light)
            {
                dp[i][]
            }
            else
            {
                dp[i][_left] = 
            }
        }   
        else 
        {
            dp[i][_left]  =min(dp[i-1][_left]+room,dp[_right]) 
            dp[i][_right] =    
        } 
    }
   
      
	return 0;
}