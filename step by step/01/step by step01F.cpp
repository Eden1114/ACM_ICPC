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
const int maxn = 105;
int les(const char *s,int p,int q)
{
    int n = strlen(s);
    for(int i = 0;i < n;i++)
    {
        if(s[(p+i)%n]!= s[(q+i)%n])
            return s[(p+i)%n] < s[(q+i)%n];
    }
    return 0;
}

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int T;
    scanf("%d",&T);
    char s[maxn];
    while(T--)
    {
        scanf("%s",s);
        int ans = 0;
        int n = strlen(s);
        for(int i = 1;i < n;i++)
            if(les(s,i,ans)) ans = i;
        for(int i = 0;i < n;i++)
            putchar(s[(i+ans)%n]);
        putchar('\n');
    }
	return 0;
}