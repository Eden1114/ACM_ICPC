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


//const double eps = 1e-8;
//const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
//const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;
const int maxn = 200 + 5;
int n;//顶点数
int case_num = 1;//样例输出


double cost[maxn][maxn];
//储存跳石头之间的距离


//储存点的坐标

double d[maxn];
bool used[maxn];

void dijkstra(int s)
{
    
    for(int i = 0;i < n;i++)
    {
        d[i] = (double)INF;
    }
    
    fill(used,used+n,false);
    d[s] = 0;
    
    
    while(true)
    {
        int v = -1;
        for(int u = 0;u < n;u++)
        {
            if(!used[u] &&  (v == -1 || d[v] >= d[u]) )
            {
                v = u;
            }
        }
        if(v == -1) break;
        used[v] = true;
        for(int u = 0;u < n;u++)
        {
            d[u] = min(d[u], max(d[v],cost[u][v]) );
        }
    }
    
}


int main(/*int argc, char *argv[]*/) {
    //ios::sync_with_stdio(false);
    while(scanf("%d",&n) == 1 && n)
    {
        int tempa;int tempb;
        vector< pair<int ,int > > points;
        for(int i = 0;i < n;i++)
        {
            scanf("%d%d",&tempa,&tempb);
            points.push_back(make_pair(tempa,tempb));
        }
        
        memset(cost, 0, sizeof(cost));
        for(int i = 0; i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(j == i)
                {
                    cost[i][j] = 0.0;
                }
                else
                {
                    cost[i][j] = cost[j][i] = sqrt((double)(
                                                   abs((points[i].first - points[j].first) * (points[i].first - points[j].first)
                                                       + (points[i].second - points[j].second) * (points[i].second - points[j].second)
                                                       )));
                }
            }
        }
        
        
        dijkstra(0);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",case_num++,d[1]);
    }
    return 0;
    
}
