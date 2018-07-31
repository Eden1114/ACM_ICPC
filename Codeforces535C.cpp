/*
 *题号：
 *时间：
 *解题思想：二分
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

LL a, b, n, l, t, m;  
    
LL getv(LL p)  
{  
    return a + (p - 1) * b;  
}  
  
  
LL getsum(LL r)  
{  
    return (getv(r) + getv(l)) * (r - l + 1) / 2;  
}  
  
  
int main()  
{  
    scanf("%lld%lld%lld", &a, &b, &n);  
    while(n--)  
    {  
        scanf("%lld%lld%lld", &l, &t, &m);  
        if(getv(l) > t) puts("-1");  
        else  
        {  
            LL le = l, ri = (t - a) / b + 1, mid;  
            while(le <= ri)  
            {  
                mid = (ri + le) / 2;  
                if(getsum(mid) <= t * m) le = mid + 1;  
                else ri = mid - 1;  
            }  
            printf("%lld\n", le - 1);  
        }  
    }  
    return 0;  
}  