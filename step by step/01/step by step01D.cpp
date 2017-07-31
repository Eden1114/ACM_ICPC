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
const int maxn = 1000 + 5;
int p[maxn];
int s[maxn];
int t[maxn];

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int x,y,n,k = 1;
    while(scanf("%d",&n) && n)
    {
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&p[i]);
            t[i] = p[i];
        }
        int flag = 0;
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&s[i]);
            if(s[i] != 0)
                flag = 1;
        }
        printf("Game %d:\n",k++);
        while(flag)
        {
            x = 0;
            y = 0;
            for(int i = 0;i < n; i++)
                if(p[i] == s[i])
                {
                    x++;
                    s[i] = p[i] = 0;
                }
            for(int i = 0;i < n; i++)
            {
                for(int j = 0;j < n; j++)
                {
                    if((p[i] == s[j]) && s[j])
                    {
                        s[j] = p[i] = 0;
                        y++;
                        break;
                    }
                }
            }
            for(int i = 0;i < n;i++)
                p[i] = t[i];
            printf("    (%d,%d)\n",x,y);
            flag = 0;
            for(int i = 0;i < n; i++)
            {
                scanf("%d",&s[i]);
                if(s[i] != 0)
                flag = 1;
            }
        }
    }
    return 0;
}