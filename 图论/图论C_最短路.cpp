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
const int maxn = 200 + 5;
int r[maxn][maxn];
int dis[maxn];
bool used[maxn];
int n;


void dijkstra(int s) {
    fill(dis, dis + maxn, INF);
    fill(used, used + maxn, false);
    
    dis[s] = 0;
    
    while(true)
    {
        int v = -1;
        for(int u = 0;u < n;u++)
        {
            if(!used[u] && (v == -1 || dis[u] < dis[v]) ) v = u;
        }
        
        if(v == -1) break;
        used[v] = true;
        
        for(int u = 0; u < n;u++)
        {
            dis[u] = min(dis[u], dis[v] + r[v][u]);
        }
    }
}

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
    int m;
	while(scanf("%d%d",&n,&m) == 2 )
    {
        int a,b,c;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                if(i == j) r[i][j] = 0;
                else r[i][j] = INF;
            
        while(m--)
        {
            scanf("%d%d%d", &a, &b, &c);
            r[a][b] = r[b][a] = min(c,r[a][b]);
        }
        
        int s,t;
        scanf("%d%d", &s, &t);
        dijkstra(s);
        printf("%d\n",dis[t] == INF ? -1 :dis[t]);
    }
	return 0;
}