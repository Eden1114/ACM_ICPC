/*
 *题号：Uva
 *时间：2017年07月26日
 *解题思想：链表的数组实现
 *
 */
//include <bits/stdc++.h>
#include <functional>
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
const int maxn = 1e5 + 5;
int last,cur,nex[maxn];
char s[maxn];

int main(/*int argc, char *argv[]*/) {
    while(scanf("%s",s+1) == 1)
    {
        int n = strlen(s+1);
        last = cur = 0;
        nex[0] = 0;
        for(int i = 1;i <= n;i++)
        {
            char ch = s[i];
            if(ch == '[')
                cur = 0;
            else if (ch == ']')
                cur = last;
            else
            {
                nex[i] = nex[cur];
                nex[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
        }
        for(int i = nex[0];i != 0;i = nex[i])
        {
            putchar(s[i]);
        }
        putchar('\n');
    }
	return 0;
}