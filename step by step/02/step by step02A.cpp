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
const int maxn = 80 + 5;
char a[maxn];
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int n;scanf("%d",&n);getchar();
    char t;
    int sum = 0;
    int O = 0;
    while(~scanf("%c",&t))
    {
        if(t == 'O'){O++;}
        else if(t == 'X'){sum += (O*O+O)/2;O = 0;}
        else if(t == '\n'){sum += (O*O+O)/2;O = 0;printf("%d\n",sum);sum = 0;}
    }
	return 0;
}