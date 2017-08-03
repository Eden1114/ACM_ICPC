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

char a[5][5];
int bx,by;//空格的位置
string cmd;
int puzzle = 1;
int exc(char cc)
{
    if(cc == 'A')
    {
        if(bx - 1 < 0) return -1;
        else 
        {
            swap(a[bx][by], a[bx-1][by]);
            bx = bx - 1;
        }
    }
    else if(cc == 'B')
    {
        if(bx + 1 > 4) return -1;
        else 
        {
            swap(a[bx][by], a[bx+1][by]);
            bx = bx + 1;
        }
    }
    else if(cc == 'R')
    {
        if(by + 1 > 4) return -1;
        else 
        {
            swap(a[bx][by], a[bx][by+1]);
            by = by+1;
        }
    }
    else if(cc == 'L')
    {
        if(by - 1 < 0) return -1;
        else 
        {
            swap(a[bx][by], a[bx][by-1]);
            by = by -1;
        }
    }
    return 0;
}
int printall(){
    printf("Puzzle #%d:\n",puzzle++);
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            if(j == 0)
                printf("%c",a[i][j]);
            else
                printf(" %c",a[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	    while(scanf("%c",&a[0][0]) == 1)
        {
            if(a[0][0] == 'Z') break;
            else 
            
            for(int i = 1;i <= 5;i++) a[0][i] = getchar();
            
            for(int i = 1;i < 5;i++)
                for(int j = 0;j <= 5;j++)
                    a[i][j] = getchar();
                            
            for(int i = 0;i < 5;i++) 
                for(int j = 0;j < 5;j++) 
                    if(a[i][j] == ' '){bx = i;by = j;}
            
            char ccc;
            char flag = true;
            while(scanf("%c",&ccc) && ccc != 'O')
            {
                if(exc(ccc) == -1) flag = false;
            }
            getchar();
            if(!flag)
            {
                printf("Puzzle #%d:\nThis puzzle has no final configuration.\n\n",puzzle++);
            }
            else
            {
                printall();
            }
        }

    return 0;
}