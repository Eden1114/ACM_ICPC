/*
 *题号：
 *时间：2018年05月15日22:51:40
 *解题思想：水
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

const int maxn = 1e5+10;
int n;
int a[maxn];

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n;
    if(n == 1) {
        cin >> n;
        cout << n << endl;
        return 0;
    }
    
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    
    if(n & 1) {
        cout << a[(n-1)/2] << endl;
    }
    else {
        cout << a[n/2-1] << endl;
    }
    return 0;
}