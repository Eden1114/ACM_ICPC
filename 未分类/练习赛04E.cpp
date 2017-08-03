/*
 *题号：
 *时间：
 *解题思想：二分图匹配：匈牙利算法
 *资料：http://blog.csdn.net/dark_scope/article/details/8880547?spm=5176.100239.blogcont18969.3.1AdcsT
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

int line[510][510],boy[510],used[510];
int n,m;
int Find(int x)
{
        int i,j;
        for(i=1;i<=m;i++)//遍历所有被选者 
        {
             if(line[x][i] == 1 && used[i] == 0)
             {//如果 x对i有好感且在这一个递归选取阶段没有被选取（哪怕是暂时选取，新的递归可能会换） 
                    used[i]=1;//标记被选取
                    if(boy[i] == 0||Find(boy[i]))
                    //如果被选者没有归属或他的归属着可以调换（他的归属者可以选择其它被选者） 
                    {
                         boy[i]=x;//将归属定为 x 
                         return 1;
                    }
             }
        }
        return 0;
}
int main()
{
    int i,j,k,x,y,sum;
    while(scanf("%d %d %d",&k,&n,&m),k!=0)
    {
        memset(line,0,sizeof(line));
        memset(boy,0,sizeof(boy));
        memset(used,0,sizeof(used));
            
        for(i=0;i<k;i++)
        {
            scanf("%d %d",&x,&y);
            line[x][y]=1;//表示 x希望与 y有关系 
        } 
             
        sum=0;//记录能撮合的情侣对数 
             
        for(i=1;i<=n;i++)  
        {
            memset(used,0,sizeof(used));//每次都要清 0 
            if(Find(i)) sum++;//找到一对就记录 
        }
        printf("%d\n",sum);
    }
    return 0;
}