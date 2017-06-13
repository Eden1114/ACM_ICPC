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
    int n;
    cin>>n;
    while(n--)
    {
        char s[110];
        cin>>s;
        int len = strlen(s);
        if(len > 10)
            cout<<s[0]<<len-2<<s[len-1]<<endl;
        else 
            cout<<s<<endl;
    }
    
}