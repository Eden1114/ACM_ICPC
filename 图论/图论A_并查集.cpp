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

const int maxn = 1e3+5;
int root[maxn];

//并查集的查
int find(int x)
{
    int r = x;
    if(root[r] != r)
    {
        r = root[r];
    }
    return r;
}

//并查集的并
void merge(int a,int b)
{
    int x,y;
    x = find(root[a]);
    y = find(root[b]);
    if(x != y)
        root[x] = y;
}

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
    int n,m;
    while(scanf("%d",&n) == 1 && n)
    {
        scanf("%d",&m);
        int a,b;
        for(int i = 0;i <= n;i++)
        {
            root[i] = i;
        }
        
        for(int i = 0;i < m;i++)
        {
            scanf("%d %d",&a,&b);
            merge(a,b);
        }
        
        int ans = 0;
        
        for(int i = 1;i <= n;i++)
        {
            if(root[i] == i) ans++;
        }
        
        printf("%d\n",ans-1);
    }	
	return 0;
}