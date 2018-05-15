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

int n;
int len;
const int maxl = 1e5+10;
string str[5];
int ans[5];
int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n;
    for(int i = 0; i < 3;i++) {
        cin >> str[i];
        int len = str[i].length();
        
        map<char , int> mp;
        int mx = -1;
        for(int j = 0; j < len; j++) {
            mp[str[i][j]] ++;
            mx = max(mx, mp[str[i][j]]);
        }

        if(mx + n <= len) 
            ans[i] = mx + n;
        else
            ans[i] = len;
        
    }
    
//    for(int i = 0;i < 3;i++)
//        cout << ans[i] << endl;
    
    
    if(ans[0] > ans[1] && ans[0] > ans[2]) {
        cout << "Kuro" << endl;
    }
    else if(ans[1] > ans[0] && ans[1] > ans[2]) {
            cout << "Shiro" << endl;
    }
    else if(ans[2] > ans[1] && ans[2] > ans[0]) {
            cout << "Katie" << endl;
    }
    else {
        cout << "Draw" << endl;
    }
    return 0;
}