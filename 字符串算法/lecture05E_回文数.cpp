/*
 *题号：
 *时间：
 *解题思想：manacher算法
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

const int maxn = 220005;
char str[maxn];
int p[maxn];

void manacher(char *s,int len)
{
    p[0] = 1;
    int mmax = 0,id = 0;
    for(int i = 1;i < len;i++)
    {
        p[i] = mmax > i ? min(p[id*2 - 1],mmax - i):1;
        while(s[i+p[i]] == s[i-p[i]]) p[i]++;
        if(i + p[i] > id + p[id])
        {
            id = i;
            mmax = i + p[i];
        }
    }
}


int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	while(~scanf("%s",str))
    {
        int len = strlen(str);
        for(int i = len;i >= 0;i--)
        {
            str[(i<<1) + 1] = '#';
            str[(i<<1) + 2] = str[i];
        }
        str[0] = '*';
        len = len * 2 + 2;
        manacher(str,len);
        int ans = 0;
        for(int i = 0;i < len;i++)
        {
            ans = max(ans,p[i]-1);
        }
        printf("%d\n",ans);
    }
	return 0;
}