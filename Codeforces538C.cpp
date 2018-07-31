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

int n,m;

/*
对于给出第一条数据（a，b），假设从第一天到第a天一直减1，
则第一天的海拔为 b + (a - 1)；
从第pre_a天海拔为pre_b，到第a天海拔为b，假设中间的最高海拔为x，
则可列出不等式（x - pre_b) + (x - b) <= a - pre_a，
整理得x = （pre_b + b + a - pre_a）/ 2；
从最后一条数据（a，b）到第n天，假设一直加1，
则第n天的海拔为b+(n-a)。每次求出一个值，求出他们的最大值即可。
*/
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    int x = -1;
    
    int ax = 0,bx = 0;
    
    for(int i = 0;i < m;i++)
    {
        int a, b;
        cin >> a >> b;
        x = max(x, b);
        
        if(i == 0) {
            x = max(x, b+a-1);
            ax = a;
            bx = b;
        }
        
        if(abs(b-bx) > abs(a-ax)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        
        int t = (b+bx+a-ax) / 2; /*!!!!!!!!!1*/
        x = max(t ,x);
        
        ax = a;
        bx = b;
        
        if (i == m - 1) {
            x = max(x, n-a+b);/*!!!!!!!!!1*/
        }
        
    }
    
    cout << x << endl;
    return 0;
}