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
int f[10000+5][10];
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int n;scanf("%d",&n);
    for(int i = 1;i < 10000;i++)
    {
        int t = i;
        while(t)
        {
            f[i][t%10]++;
            t /= 10;
        }
        for(int k = 0;k <= 9;k++)
        {
            f[i][k] += f[i-1][k];
        }
    }

    for(int _ = 0; _ < n;_++)
    {
        int v;scanf("%d",&v);
        for(int i = 0;i <= 9;i++)
        {
            if(i == 0) printf("%d",f[v][i]);
            else printf(" %d",f[v][i]);
        }
        putchar('\n');
    }
	return 0;
}