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
int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	int n,m;
    map<int,vector<int> > a;
    while(scanf("%d%d",&n,&m) == 2)//many case
    {
        a.clear();
        int read;
        for(int i = 0;i < n;i++)
        {
           scanf("%d",&read);
           if(!a.count(read))
               a[read]= vector<int>();
           a[read].push_back(i+1);
    }
        
        
            int k,v;
            for(int i = 0; i < m;i++)
            {
                scanf("%d%d",&k,&v);
                if(!a.count(v) ||k > a[v].size() ) cout<<"0"<<endl;
                // 要查找的数字不在里面，或者是查找的范围超出了实际存在的范围
                else cout<<a[v][k-1]<<endl;
        }
    }
    return 0;
}