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
const int maxn = 4010;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int cd[maxn*maxn];

int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    
    int n,sum = 0;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    
    int index = 1;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cd[index++] = c[i] + d[j];
        }
    }
    //cout<<index;
    
    sort(cd+1,cd+index);
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int x = -(a[i] + b[j]);
            if(binary_search(cd+1, cd+index, x))
            {
                int t = upper_bound(cd+1, cd+index, x)-lower_bound(cd+1, cd+index, x);
                sum += t;
            }
        }
    }
    
    cout<<sum<<endl;
    return 0;
}