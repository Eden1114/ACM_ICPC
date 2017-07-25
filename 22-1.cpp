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
    int a[1010];
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    
    int status = -2;
    if(n == 1)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    else
    for(int i = 1;i < n;i++)
    {
        if(status == -2)
        {
            if(a[i] > a[i-1])
            {
                status = 1;
            }
            else if(a[i] == a[i-1])
            {
                status = 0;
            }
            else
            {
                status = -1;
            }
        }
        
        else if(status == 1)
        {
            if(a[i] == a[i-1])
            {
                status = 0;
            }
            else if(a[i] < a[i-1])
            {
                status = -1;
            }
        }
        
        else if(status == 0)
        {
            if(a[i] > a[i-1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            else if (a[i] < a[i-1])
            {
                status = -1;
            }
        }
        
        else if(status == -1)
        {
            if(a[i] >= a[i-1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}