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
char a[110][110];
int main(){
    int n,m;
    cin>>m>>n;
    int black = 0;
    int left = 101,right = 0,up = 101,down = 0;
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cin>>a[i][j];
            if(a[i][j] == 'B')
            {
                black++;
                up = min(up,i);
                down = max(down,i);
                left = min(left,j);
                right = max(left,j);
            }
        }
    }
    if(black == 0) {cout<<1<<endl;}
    int len = max(down-up,right-left);
    
    if( 
        (left + len > n && right - len < 1)
        || (up + len > m && down - len < 1)
      )
    {cout<<-1<<endl;return 0;}
    
    else
    {
        len++;
        cout<<len*len - black<<endl;
    }
}