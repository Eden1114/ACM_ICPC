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

int a[1000],d[1000];

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
    int n; 
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
            d[i] = 1;
        }
        
        for(int i = 1;i < n;i++)
            for(int j = 0; j < i;j++)
            {
                if(a[i] > a[j] && d[i] < d[j] + 1)
                {
                    d[i] = d[j] + 1;
                }
            }
        int ma = -1;
        for(int i = 0;i < n;i++)
        {
            ma = max(d[i],ma);
        }
        printf("%d\n",ma);
    }
	return 0;
}