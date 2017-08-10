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
int r[3003],u[3003],s[3003];  

int main()  
{  
    int a,b;
    int idx = 0;
    int t;
    scanf("%d%d",&a,&b);
    set<int > s;
    while (a != 0) {
            r[idx++] = a/b;
            t = a % b;
            a = (a%b)*10;
            printf("%d",r[idx-1]);
            if(s.count(t)){break;}
            else(s.insert(t));
    }
      
    return 0;  
}