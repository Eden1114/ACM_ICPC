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
    int ans = 0;
    int temp;
    int flag = 0;
    
    for(int i = 0; i < n;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            cin>>temp;
            if (temp) flag++;
        }
        
        if(flag >= 2) ans++;
        flag = 0;
    }
    cout<<ans<<endl;
    return 0;
}