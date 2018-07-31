/*
 *题号：
 *时间：
 *解题思想：找规律 DP
 *
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <cstring>
#include <climits>
#include <limits>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

const double eps=1e-8,pi=acos(1.0*(-1));
const int INF=0x3f3f3f3f,mod=1e9+7;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef std::pair<int,int> P;
typedef long long LL;
typedef long long ll;
using namespace std;

const int maxn = 5000 + 5;
int n;

int a[maxn];
int dp[maxn];

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n;
    for(int i =1;i <= n;i++)
    {
        cin >> a[i];
    }
    
//    dp[1] = a[1];
//    for(int i = 2; i <= n;i++)
//    {
//        dp[i] = a[i] ^ dp[i-1];
//    }
    
    int m;
    cin >> m;
    for(int i = 0;i < m;i++)
    {
        int l,r;
        cin >> l >> r;
        int ans = a[l];
        ans ^= a[l+1];
        ans ^= a[r-1];
        ans ^= a[r];
        cout << ans << endl;
    }
    
    return 0;
}