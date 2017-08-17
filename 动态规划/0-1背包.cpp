/*
 *题号：
 *时间：
 *解题思想：动态规划入门
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
const int INF = 0x3f3f3f3f;


using namepace std;
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    //N件物品 体积 Vi 价值 Wi  求一个背包
    int v[1000011];
    int dp[1000111];
    int n,m;
    cin>>n>>m;
    int a,b;
    int count = 0;
    for(int i = 1; i <= n;i++)
    {
        cin>>a>>b;
        for(int k = 1;k <= b;k <<= 1)
        {
            v[count++] = a*k;
            b = b - k;
        }
        if(b > 0)
        {
            v[count++]= b * a;
        }
    }
    
    for(int i = 0; i < count;i++)
    {
        for(int j = m;j >= v[i];j--)
        {
            dp[j] = max(dp[j],dp[j-v[i]] + v[i]);
        }
    }
    
    printf("%d\n",dp[m]);
    return 0;
}