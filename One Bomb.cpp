#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
using namespace std;
struct Point{
    int x;
    int y;
} points[2001];

int compare(int x,int y,struct Point z){
    if(x == z.x || y == z.y) return 1;
    else return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int m,n;
    char x;
    int l = 0;
    cin>>m>>n;
    for(int i = 0; i < m;i++)
    {
        for(int j = 0 ; j <= n; j++)
        {
            scanf("%c",&x);
            if(x == '*')
            {
                points[l].x = i;
                points[l].y = j;
                l++;
            }
        }
    }
    for(int i = 0; i < m;i++)
    {
        for(int j = 0 ; j < n;j++)
        {
            int t = 1;
            for(int v = 0;v < l;v++)
            {
                if(compare(i, j, points[v]) == 0)
                {	
                    t = 0;
                    break;
                }
            }
            if(t == 1)
            {
                puts("YES\n");
                printf("%d %d\n",i + 1,j);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}