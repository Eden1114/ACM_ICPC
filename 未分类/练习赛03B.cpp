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
int cnt[7500];
int coin[5] = {1,5,10,25,50};
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	cnt[0] = 1;
    for(int i = 0;i < 5;i++)
    {
        for(int j = coin[i]; j < 7500; j++)
        {
            cnt[j] += cnt[j-coin[i]];
        }
    }
    int n;
    while(scanf("%d",&n) == 1)
    {
        printf("%d\n",cnt[n]);
    }
    
	return 0;
}