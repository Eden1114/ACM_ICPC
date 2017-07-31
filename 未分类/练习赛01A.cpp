/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define F(i,a,b) for(int i = a; i < b; i++)

using namespace std;

const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

bool p[5],s[5],l[5],r[5];

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	for(int i = 1;i <= 4;i++)
        cin>>l[i]>>s[i]>>r[i]>>p[i];
           
    bool flag = false;
    if(p[1])
    {
        if(l[1] || r[1] || s[1] || s[3] || l[2] || r[4])
        {
            flag = true;
        }
    }
    
    if(p[2])
    {
        if(l[2] || r[2] ||s[2] || s[4] || l[3] || r[1])
        {
            flag = true;
        }
    }
    
    if(p[3])
    {
        if(l[3] || r[3] ||s[3] || s[1] || l[4] || r[2])
        {
            flag = true;
        }
    }
    if(p[4])
    {
        if(l[4] || r[4] ||s[4] || s[2] || l[1] || r[3])
        {
            flag = true;
        }
    }
    
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
	return 0;
}