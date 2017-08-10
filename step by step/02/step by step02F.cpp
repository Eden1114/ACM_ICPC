/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

#define F(i,a,b) for(int i = a; i < b; i++)


const double eps = 1e-8;
const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;

int main()
{
    char s[11][11];
    int r, c, i, j, k, a[11][11], d[11][11], first=1, count=0;
    while (~scanf("%d",&r)&&r)
    {
        scanf("%d", &c);
        for (i = 1;i <= r;i++)
            scanf("%s", s[i]+1);
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        k = 0;
        for (i = 1;i <= r;i++)
            for (j = 1;j <= c;j++)
            {
                if (s[i][j]!='*') a[i][j] = 1;//a[i][j]=1表示白格
                if (a[i][j]&&(a[i][j-1]==0||a[i-1][j]==0)) d[i][j] = ++k;//d[i][j]=k表示该起始格的编号是k
            }
        if (first) first = 0;
        else putchar('\n');
        printf("puzzle #%d:\nAcross\n", ++count);
        for (i = 1;i <= r;i++)
            for (j = 1;j <= c;j++)
            {
                if (d[i][j] && a[i][j-1] ==0)//
                {
                    printf("%3d.", d[i][j]);//
                    for (k = j;a[i][k] == 1 && k <= c;k++)
                        putchar(s[i][k]);
                    putchar('\n');
                }
            }
        printf("Down\n");
        for (i = 1;i <= r;i++)
            for (j = 1;j <= c;j++)
            {
                if (d[i][j]&&a[i-1][j]==0)
                {
                    printf("%3d.", d[i][j]);
                    for (k = i;a[k][j] == 1 && k <= r;k++)
                        putchar(s[k][j]);
                    putchar('\n');
                }
            }
    }
    return 0;
}