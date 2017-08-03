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
 
int per[110];
struct node
{
    int b,e,v;
} s[5050];
bool cmp(node x,node y)
{
    return x.v<y.v;
}
void init()
{
    for(int i = 0;i < 110;i++)
    per[i] = i;
}
int find(int x)
{
    while(x!=per[x])
    x=per[x];
    return x;
}
bool join (int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        per[fx]=fy;
        return true;
    }
    return false;
}


int main()
{
    int n,i,flag;
    while(scanf("%d",&n) == 1 && n)
    {
        init();
        int m=n*(n-1)/2;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&s[i].b,&s[i].e,&s[i].v,&flag);
            if(flag)//最主要的就是把修过的路的价值清0
            s[i].v=0;
        }
        sort(s,s+m,cmp);
        int sum=0;
        for(i=0;i<m;i++)
        {
            if(join(s[i].b,s[i].e))
            sum+=s[i].v;
        }
        printf("%d\n",sum);
    }
    return 0;
}