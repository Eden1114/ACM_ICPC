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
char a[99];
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>a;
    int add=0;
    int num[99];
    num[0] = 0;
    for(int i = 1; i <= n;i++)
    {
        num[i] = a[i-1] - '0';
    }
    
    if(a[n-1] == '1')
    {
        num[n+1] = 0;
        vector<int> zero_index;
        for(int i = )
    }
    else if(a[n - 1] == '0')
    {
        for(int i = 0;i < n;i++)
        {
            if(num[i] == 1) add++;
            else if(num[i] == 0)
            {
                cout<<add;
                add = 0;
            }
        }
    }
    
    putchar('\n');
    return 0;
}