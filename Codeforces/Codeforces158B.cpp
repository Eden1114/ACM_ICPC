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
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n,t;
    int a[123];memset(a,0,sizeof(a));
    int res = 0;
    cin>>n;
    F(n)
    {
        cin>>t;
        a[t]++;
    }
    res += a[4];
    a[4] = 0;
    //cout<<res<<endl;
    if(a[3] >= a[1])
    {
        res += a[3];
        a[1] = a[3] = 0;
    }
    else
    {
        res += a[3];
        a[1] -= a[3];
        a[3] = 0;
    }
    
    if(2 * a[2] >= a[1])
    {
        a[2] -= (a[1]+1)/2;
        res += (a[1]+1)/2;
        a[1] = 0;
    }
    else
    {
        res += a[2];
        a[1] -= 2*a[2];
        a[2] = 0;
    }
    if(a[2])
        res += (a[2]+1)/2;
    
    res += (a[1]+3)/4;
    cout<<res<<endl;
    return 0;
}