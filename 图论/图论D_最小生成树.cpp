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
 

// 定义图的最大顶点数
const int MaxVertexNum = 105;
// 定义图的最大边数
const int MaxEdgeNum = 105*52+2;
const int Max = 0xFFFFFFF;
 
struct edge
{
    int from;
    int end;
    double length;
};
 
edge edgeset[MaxEdgeNum];
double node[MaxVertexNum][2];
 
bool compare(const struct edge& a,const struct edge& b) 
{ 
    return a.length<b.length; 
} 
  
int Kruskal(edge e[MaxEdgeNum],edge c[MaxEdgeNum],const int& vertexs) 
{ 
    int i,j,k,d; 
    // 定义m1和m2来分别记录一条边的两个顶点所在的集合的序号 
    int m1,m2; 
       
    int s[MaxVertexNum][MaxVertexNum]; 
    // 初始化 
    for(i = 0; i < vertexs; i++) 
        for( j = 0; j < vertexs; j++) 
        { 
            if( i == j) 
                s[i][j] = 1; 
            else
                s[i][j] = 0; 
        } 
    // 最小生成树的边数 
    k = 0; 
    d = 0; 
   
    while(k < vertexs - 1) 
    { 
        for(i = 0;i < vertexs; i++) 
        { 
            if(s[i][e[d].from] == 1) 
                m1 = i; 
            if(s[i][e[d].end] == 1) 
                m2 = i; 
        } 
        if(m1 != m2) 
        { 
            c[k++] = e[d]; 
            for(j = 0;j < vertexs;j++) 
            { 
                s[m1][j]=s[m1][j]||s[m2][j]; 
                s[m2][j]=0; 
            } 
        } 
        d++; 
    } 
    return k; 
} 
   
 
int main(int argc, char* argv[])
{
    int t,n;
    int i,j,k,r,flag;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        flag=1;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lf%lf",&node[j][0],&node[j][1]);
        }
 
        k=0;
        for(j=0;j<n-1&&flag;j++)
        {
            for(r=j+1;r<n;r++)
            {
                double length=sqrt((node[j][0]-node[r][0])*
                    (node[j][0]-node[r][0])+(node[j][1]-node[r][1])*
                    (node[j][1]-node[r][1]));
                // 注意这里吖
                if(length<10||length>1000)
                {
                    length=Max;
                }
                edgeset[k].from=j;
                edgeset[k].end=r;
                edgeset[k].length=length;
                k++;
            }
        }
 
        edge c[MaxEdgeNum];
        sort(edgeset,edgeset+k,compare);
        int edges=Kruskal(edgeset,c,n);
        double MinLength=0;
        for(j=0;j<edges;j++)
        {
            if(c[j].length==Max)
            {
                flag=0;
                printf("oh!\n");
                break;
            }
            MinLength+=c[j].length;
        }
        if(flag)
            printf("%.1lf\n",MinLength*100);
    }
    return 0;
}