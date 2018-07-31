/*
 *题号：
 *时间：
 *解题思想：模拟
 *
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


const int maxn = 1e2 + 20;
char mp[maxn][maxn];
int n,m;

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        scanf("%s", mp[i]+1);
    }
    bool flag = true;
    for(int i  = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if((mp[i][j]>= '0' && mp[i][j] <= '9') || mp[i][j] == '.')
            {
                int ans = 0;
                for(int dx = -1;dx <= 1;dx++)
                {
                    for(int dy = -1;dy <= 1;dy++)
                    {
                        if(dx == 0 && dy == 0) continue;
                        else if(i+dx >= 1 && i +dx <= n 
                                          && j +dy >= 1 
                                          && j +dy <= m 
                                          && mp[i+dx][j+dy] == '*') {
                            ans++;
                            
                        }
                    }
                }
                //cout << ans << endl;
                if(mp[i][j] == '.' && ans != 0) {
                    flag = false;
                }
                else if(mp[i][j] >= '0' && mp[i][j] <= '9' && ans != mp[i][j] - '0') {
                        flag = false;
                }
            
            }
        }
    }
    if(flag) cout << "YES" <<endl;
    else cout << "NO" << endl;
    return 0;
}