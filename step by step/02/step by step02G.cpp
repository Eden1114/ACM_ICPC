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

struct DNA {  
    int a, t, c, g;  
}d[1005];  
char s[1005];  
int main() {  
    int kase;  
    scanf("%d", &kase);  
    char q;  
    while(kase--) {  
        int n, m;  
        scanf("%d%d", &n, &m);  
        for(int i=0; i<m; i++) d[i].a=d[i].t=d[i].c=d[i].g=0;  
        for(int i=0; i<n; i++) {  
            scanf("%s", s);  
            for(int j=0; j<m; j++) {
                if(s[j] == 'A') d[j].a++;  
                else if(s[j] == 'T') d[j].t++;  
                else if(s[j] == 'C') d[j].c++;  
                else if(s[j] == 'G') d[j].g++;  
            }  
        }  
        int maxn = 0;  
        int ans = 0;  
        for(int i=0; i<m; i++) {  
            maxn = 0; 
            if(maxn < d[i].a) {s[i] = 'A'; maxn = d[i].a;}  
            if(maxn < d[i].c) {s[i] = 'C'; maxn = d[i].c;}  
            if(maxn < d[i].g) {s[i] = 'G'; maxn = d[i].g;}  
            if(maxn < d[i].t) {s[i] = 'T'; maxn = d[i].t;}  
            ans += n-maxn;  
        }  
        s[m] = 0;  
        printf("%s\n%d\n", s, ans);  
    }  
    return 0;  
}  