/*
 *题号：
 *时间：
 *解题思想：最小生成树
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
const int maxv = 100 + 5;
int cost[maxv][maxv];
int mincost[maxv];
bool used[maxv];
int v;

int prim() {
    for(int i = 1; i <= v;i++)
    {
        mincost[i] = INF;
        used[i] = false;
    }
    
    mincost[1] = 0;
    int res = 0;
    
    while(true)
    {
        int n = -1;
        for(int u = 1;u <= v;u++)
        {
            if(!used[u] && (n == -1 || mincost[u] < mincost[v])) n = u;
            //选择没有加入生成树，且权值最小的结点加入到X
        }
        if(n == -1) break;//都加入完了，就结束循环吧
        
        used[n] = true;//标记顶点，表示添加过了
        
        res += mincost[n];//结果是加上权值
        
        for(int u = 1; u <= v; u++)
        {
            mincost[u] = min(mincost[u], cost[n][u]);
        }
        //这一步用来更新未加入的定点到生成树X的最小消耗
    }
    return res;
}



int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	while(scanf("%d",&v) == 1 && v)
    {
        memset(cost,0, sizeof(cost));
        for(int i = 1; i <= v*(v-1)/2 ; i++)
        {
            int a,b,c;
            scanf("%d%d%d", &a, &b, &c);
            cost[a][b] = cost[b][a] = c;        
        }	

        printf("%d\n",prim());
    }
    return 0;
}