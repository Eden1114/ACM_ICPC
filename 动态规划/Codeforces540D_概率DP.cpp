/*
 *题号：Codeforces 540D
 *时间：2018年05月10日20:41:46
 *解题思想：概率DP
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

const int maxn = 100 + 10;
double dp[maxn][maxn][maxn];

double cal(int a,int b,int c)  
{  
    if(a*b+b*c+c*a == 0)
        return 0;
    else 
        return (1.0 * (a*b) / (a*b+b*c+c*a));
}  

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    int r,s,p;
    cin >> r >> s >> p;
    dp[r][s][p] = 1;
    for(int i = r; i >= 0; i--) {
        for(int j = s; j >= 0; j--) {
            for(int k = p; k >= 0; k--) {
                if(i-1>=0) dp[i-1][j][k] += dp[i][j][k]*cal(i,k,j);  
                if(j-1>=0) dp[i][j-1][k] += dp[i][j][k]*cal(i,j,k);  
                if(k-1>=0) dp[i][j][k-1] += dp[i][j][k]*cal(j,k,i);  
            }
        }
    }
    
    double a,b,c;
    a = b = c = 0;
    for(int i = 0; i <= r; i++) a += dp[i][0][0];
    for(int i = 0; i <= s; i++) b += dp[0][i][0];
    for(int i = 0; i <= p; i++) c += dp[0][0][i];

    printf("%.12lf %.12lf %.12lf\n",a,b,c);
    return 0;
}