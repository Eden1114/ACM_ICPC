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
const int maxn = 1e5+5;
struct hanoi{
    int  inner;
    int  outer;
    int  height;
};
struct hanoi a[maxn];
stack<struct hanoi> s;

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int n;cin>>n;
    while(!s.empty())
    {
        s.pop();
    }
    for(int i = 0; i < n;i++)
    {
        struct hanoi temp;
        cin>>a[i].inner>>a[i].outer>>a[i].height;
    }
    
    sort(a,a+n,[=](struct hanoi a,struct hanoi b){
        if(a.outer == b.outer) return a.inner > b.inner;
        return a.outer > b.outer;});
    
    s.push(a[0]);
    long long  sum = a[0].height;
    long long ans = a[0].height;
    
    for(int i = 1; i < n;i++)
    {
        
        while(!s.empty() && a[i].outer <= s.top().inner )// <=
        {
            sum -= s.top().height;
            s.pop();
        }
        sum += a[i].height;
        ans = max(ans,sum);
        s.push(a[i]);
    }
    
    printf("%I64d\n",ans);
	return 0;
}