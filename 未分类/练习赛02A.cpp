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

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	int n;int x;
    cin>>n>>x;
    int t = n;
    int a[3] = {0,0,0};
    
    a[x] = 1;
    if(t > 6) t = t % 6;
    while(t)
    {
        if(t % 2){swap(a[0], a[1]);}
        else{swap(a[1],a[2]);}
        t--;
    }
    
    for(int i = 0;i < 3;i++)
    {
        if(a[i]) cout<<i<<endl;
    }
	return 0;
}