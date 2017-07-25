/*
 *题号：
 *时间：
 *解题思想：二分答案
 *
 */
//include <bits/stdc++.h>
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

using namespace std;

const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

const int maxn = 100000;

bool check(int dis){
    int cnt = 0;last = 0;
    for(int i = 1;i <= n;i++)
    {
        if(d[i] - d[last] >= dis) last = i;
        else cnt++;
    }
    if(cnt > m ) return false;
    if(L-d[last] < dis) return false;
    return true;
}

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
    int n,l,m;
    int d[maxn];
    int L = 1,R = 0;
    scanf("%d%d%d",&l,&n,&m);
    //l是距离，n是长度，m是可以移除的石头
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&d[i]);
        //d[i]是第i块石头到起点的距离
        R = max(R,d[i]);
    }

    R = max(l,R);
    while(L < R)
    {
        int mid = l + (r - l + 1)/2;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout<<l<<endl;
	return 0;
}