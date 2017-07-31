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
char a[110][110];
int main(){
    int n,m;
    cin>>m>>n;
    int black = 0;
    int ans = 0;
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
    int len = max(down - up,right - left);

    if(len + 1 > n || len + 1 > m) {cout<<-1<<endl;return 0;}
    else if(black == 0) {cout<<1<<endl;return 0;}
    else {cout<<len*len - black<<endl;return 0;}
}