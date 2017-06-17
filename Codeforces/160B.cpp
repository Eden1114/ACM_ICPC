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
    int n;
    cin>>n;
    char s[210];
    cin>>s;
    sort(s,s+n);
    sort(s+n,s+2*n);
    int flag = 1;
    int status = 1;
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] <= s[i+n]) status = 0;
        if(s[i] >= s[i+n]) flag = 0;
    }
    
    if(status || flag)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
        
    return 0;
}