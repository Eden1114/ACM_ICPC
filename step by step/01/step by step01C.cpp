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
const int maxn = 1e5;
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[]={"not a palindrome",
                   "a regular palindrome",
                   "a mirrored string",
                   "a mirrored palindrome"};
char r(char ch)
{
    if(isalpha(ch)) return rev[ch-'A'];
    return rev[ch-'0' + 25];
}
int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
    char s[maxn];
	while(scanf("%s",s) == 1)
    {
        int len = strlen(s);
        int p = 1;
        int m = 1;
        for(int i = 0; i < (len+1)/2;i++)
        {
            if(s[i] != s[len-1-i]) p = 0;
            if(r(s[i])!= s[len-1-i])  m = 0;
        }
        printf("%s -- is %s.\n\n",s , msg[2*m + p]);
    }
	return 0;
}