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
    long long m,n,t;
    cin>>m>>n>>t;
    long long a,b;
    a = m/t;b = n/t;
    if(m%t) a++;
    if(n%t) b++;
    cout<<a*b<<endl;
    return 0;
}