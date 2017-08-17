/*
 *题号：http://www.bnuoj.com/v3/contest_show.php?cid=6865#problem/C
 *时间：
 *解题思想：KMP变形
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

int const maxn = 5e6 + 5;
char s1[maxn],s2[maxn],ans[maxn];
int nextt[maxn];
int pos[maxn];

int l1,l2,cnt;

void get_nextt()
{
    int i = 0,j = -1;
    nextt[0] = -1;
    while(s2[i])
    {
        if(j == -1 || s2[i] == s2[j])
        {
            i++;j++;
            if(s2[i] == s2[j])
                nextt[i] = nextt[j];
            else 
                nextt[i] = j;
        }
        else
            j = nextt[j];
        
    }
}

void KMP()
{
    get_nextt();
    int i = 0, j = 0;
    cnt = 0;
    while(s1[i])
    {
        ans[cnt] = s1[i++];
        while(!(j == -1 || ans[cnt] == s2[j]))
        {
            j = nextt[j];
        }
        j++;
        cnt++;
        pos[cnt] = j;
        if(j == 12)
        {
            cnt -= 12;
            j = pos[cnt];
        }
    }
}
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	while(scanf("%s %s",s2,s1) != EOF)
    {
        l1 = strlen(s1);
        l2 = strlen(s2);
        KMP();
        for(int i = 0; i < cnt; i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
	return 0;
}