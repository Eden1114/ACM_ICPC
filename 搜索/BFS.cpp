/*
 *题号：Codeforces 540C
 *时间：2018年05月10日21:47:48
 *解题思想：BFS
 *遇到这种从起始点到某一个重点的，一般是搜索。
 *如果有限制条件，一般就是BFS？
 *类似以前做过的跳路径？
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <cstring>
#include <climits>
#include <limits>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

const double eps=1e-8,pi=acos(1.0*(-1));
const int INF=0x3f3f3f3f,mod=1e9+7;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef std::pair<int,int> P;
typedef long long LL;
typedef long long ll;
using namespace std;

const int maxn = 500 + 10;
const int maxm = 500 + 10;
int n, m;

char mp[maxn][maxm];
typedef struct point {
    int x;
    int y;
    
    point(int x=0,int y=0) {
        this->x = x;
        this->y = y;
    }
    
    void setpoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    bool operator == (struct point &t) {
        if(this->x == t.x && this->y == t.y) return true;
        return false;
    }
} Point;

Point s,d;
int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> (mp[i] + 1);
    queue<Point> q;
    
    cin >> s.x >> s.y;
    cin >> d.x >> d.y;
    
    q.push(s);
    while (q.size()) {
        Point t = q.front();
        
        if(t.x >= 2) {
            Point tt(t.x-1, t.y);
            if(tt == d)
            {
                if(mp[tt.x][tt.y] == 'X')//到达（r2，c2）且map[r2][c2]='X'
                {
                    puts("YES");
                    return 0;
                }
                else//到达//（r2，c2）且map[r2][c2]='.'
                {
                    mp[tt.x][tt.y] = 'X';
                    q.push(tt);
                }
            }
            else if(mp[tt.x][tt.y] == '.')
            {
                mp[tt.x][tt.y] = 'X';
                q.push(tt);
            }
            //else q.push(tt);
        }
        
        
        if(t.y >= 2) {
            Point tt(t.x, t.y-1);
            if(tt == d)
            {
                if(mp[tt.x][tt.y] == 'X')//到达（r2，c2）且map[r2][c2]='X'
                {
                    puts("YES");
                    return 0;
                }
                else//到达//（r2，c2）且map[r2][c2]='.'
                {
                    mp[tt.x][tt.y] = 'X';
                    q.push(tt);
                }
            }
            else if(mp[tt.x][tt.y] == '.')
            {
                mp[tt.x][tt.y] = 'X';
                q.push(tt);
            }
            //else q.push(tt);
        }
        
        
        if(t.x <= n-1) {
            Point tt(t.x+1, t.y);
            if(tt == d)
            {
                if(mp[tt.x][tt.y] == 'X')//到达（r2，c2）且map[r2][c2]='X'
                {
                    puts("YES");
                    return 0;
                }
                else//到达//（r2，c2）且map[r2][c2]='.'
                {
                    mp[tt.x][tt.y] = 'X';
                    q.push(tt);
                }
            }
            else if(mp[tt.x][tt.y] == '.')
            {
                mp[tt.x][tt.y] = 'X';
                q.push(tt);
            }
            //else q.push(tt);
        }
        
        
        if(t.y <= m-1) {
            Point tt(t.x, t.y+1);
            if(tt == d)
            {
                if(mp[tt.x][tt.y] == 'X')//到达（r2，c2）且map[r2][c2]='X'
                {
                    puts("YES");
                    return 0;
                }
                else//到达//（r2，c2）且map[r2][c2]='.'
                {
                    mp[tt.x][tt.y] = 'X';
                    q.push(tt);
                }
            }
            else if(mp[tt.x][tt.y] == '.')
            {
                mp[tt.x][tt.y] = 'X';
                q.push(tt);
            }
            //else q.push(tt);
        }
        
        q.pop();
    }
    
    puts("NO");
    return 0;
}