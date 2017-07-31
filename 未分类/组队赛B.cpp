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
const int maxn = 1e5 + 5;
int a[maxn],b[maxn],c[maxn],v[maxn];

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int n;
    while(scanf("%d",&n)== 1 && n)
    {
        for(int i = 1; i <= n;i++)
            scanf("%d",&a[i]);
        
        memset(v, 0, sizeof(v));
        for(int i = 1;i <= n;i++)
        {
            if(v[a[i]])
            {
                b[i] = a[v[a[i]]];
            }
            else
            {
                b[i] = a[i];    
            }
            
            
            for(int j = 1;j <= (int)(sqrt(a[i])+0.5);j++)
            {
                if (a[i] %j ==0)
                {
                    v[j] = i;
                    v[a[i]/j] = i;
                }
            }
        }

        memset(v, 0, sizeof(v));
        for(int i = n; i >= 1;i--)
        {
            if(v[a[i]])
            {
                c[i] = a[v[a[i]]];
            }
            else
            {
                c[i] = a[i];    
            }
            
            for(int j = 1;j <= (int)(sqrt(a[i])+0.5);j++)
            {
                if (a[i] % j == 0)
                {
                    v[j] = i;
                    v[a[i]/j] = i;
                }
            }
        }
        
        long long ans = 0;
        for(int i = 1;i <= n;i++)
        {
            ans += b[i]*c[i];
        }
        cout<<ans<<endl;
    }
	return 0;
}