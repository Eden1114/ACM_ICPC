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

const int maxn = 2000000 + 5;
using namespace std;

int a[maxn];
int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	int n;
    while(scanf("%d",&n) && n)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i = 0;i < n;i++)
        {
            printf("%d",a[i]);
            if(i != n - 1)
            {
                putchar(' ');
            }
            else
            {
                putchar('\n');
            }
        }
    }
	return 0;
}