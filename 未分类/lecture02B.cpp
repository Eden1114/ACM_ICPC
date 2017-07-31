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
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
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
const int maxn = 1e5 + 5;
int a[maxn];
int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	int T;scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int m = -INF;
        int max_p = -INF;
        F(i,0,n)
        {
            scanf("%d",&a[i]);
            if(i - 1 >= 0)
            {
                max_p = max(max_p,a[i-1]);
            }
            m = max(m, max_p - a[i]);
        }
        cout<<m<<endl;
    }

	return 0;
}