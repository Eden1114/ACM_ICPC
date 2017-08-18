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
char a[5][5] = {"***","*.*","***","*.*","*.*"};
char b[5][5] = {"***","*.*","***","*.*","***"};
char c[5][5] = 
{"***","*..","*..","*..","***"};
char d[5][5] = 
{"***","*.*","*.*","*.*","***"};
char e[5][5] = {"***","*..","***","*..","***"};
char s[2018];
int main() {
	//ios::sync_with_stdio(false);
	int n;scanf("%d",&n);
    scanf("%s",s);
    
    
    for(int j = 0;j < 5;j++)
    {
        for(int i = 0;i < n;i++)
        {
            if(s[i] == 'A')
                printf("%s",&a[j]);
            else if(s[i] == 'B')
                printf("%s",&b[j]);
            else if(s[i] == 'C')
                printf("%s",&c[j]);
            else if(s[i] == 'D')
                printf("%s",&d[j]);
            else if(s[i] == 'E')
                printf("%s",&e[j]);    
        }
        putchar('\n');
    }
    
	return 0;
}