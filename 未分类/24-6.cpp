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
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
#define F(n) for(int i = 0; i < n; i++)
const int maxn = 50000 + 5;
pair<int,int> a[maxn];
int weight[maxn];

int cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first + a.second < b.first + b.second;
}

int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 0; i < n;i++)
    {
        cin>>a[i].first>>a[i].second;
        sum += a[i].first;
    }
    sort(a,a+n,cmp);
    int ans = -INF;
    
    for(int i = n-1; i >= 0;i--)
    {
        sum -= a[i].first;
        ans = max(ans,sum-a[i].second);
    }
    cout<<ans<<endl;
    return 0;
}