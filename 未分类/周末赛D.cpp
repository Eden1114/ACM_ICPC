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

char a[205][205];
bool b[205][205];
int r,c;
int ans;
int flag;
void dfs(int x,int y)
{
    if(x > r || x <= 0 || y > c || y <= 0){flag = -2;return;}
    if(b[x][y] == true){flag = -1;return;}
    
    ans++;
    b[x][y] = true;
    //cout<<x<<y<<endl;
    if(a[x][y] == 'T'){return;}
    
    else if(a[x][y] == 'S'){dfs(x+1,y);}
    else if(a[x][y] == 'W'){dfs(x,y-1);}
    else if(a[x][y] == 'E'){dfs(x,y+1);}
    else if(a[x][y] == 'N'){dfs(x-1,y);}
    
}

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
    scanf("%d%d",&r,&c);
    getchar();
    memset(b,0,sizeof(b));
    ans = 0;
    flag = 1;
    for(int i = 1;i <= r; i++)
    {
        for(int j = 1;j <= c+1;j++)
        {
           a[i][j] = getchar();
        }
    }
    
    
    dfs(1,1);
    if(flag == -2){printf("Out\n");}
    else if(flag == -1){printf("Lost");}
    else if(flag == 1 && ans){printf("%d\n",ans-1);}
	return 0;
}