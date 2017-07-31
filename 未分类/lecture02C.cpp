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
set<int> vis;
int n;
long long k;

long long ow(long long k)
{
    long long ans = 0;
    long long t = k * k;
    long long save[20];
    int saven = 0;
    while(t)
    {
        save[saven++] = t%10;
        t /= 10;
    }
    for(int i = saven - 1;i > max(saven - 1 - n,-1);i--)
    {
        ans = ans * 10 + save[i];
        return ans;
    }
}

int solve() {
    int ans = 0;
    while(vis.find(k) == vis.end())
    {
        if(ans < k) ans = k;
        vis.insert(k);
        k = ow(k);
    }
    return ans;
}

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	int t;cin>>t;
    while(t--)
    {
        cin>>n>>k;
        //屏幕显示n个数字，输入k
        vis.clear();
        printf("%d\n",solve());
    }
	return 0;
}