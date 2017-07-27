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
const int maxn = 5 * 1e5 + 5;


vector<string> str;


void solve(int i){

    char *p = &str[i][0];//上面的串
    char *q = &str[i+1][0];//下面的串
    while(1)
    {
        if(*p == '\0') break;//上面的串到头了，或者两个都到头了
        
        if(*q == '\0')//下面的串到头，上面的串没有到头了
        {
            *p = '\0';
            break;
        }
        //两个都没到头
        if(*p > *q)
        //如果p指向的字母的ascii码大,上面字符的字典序大
        {
            *p = '\0';
            break;
        }
        if( *p < *q) break;
        if( *p == *q)
        {
            p++;    
            q++;
        }
    }
 
}

int main(/*int argc, char *argv[]*/) {
	int n;  cin>>n;
    string temp;
    
    for(int i = 0; i < n;i++)
    {
        cin>>temp;
        str.push_back(temp);
    }
        
    for(int i = n-2;i >= 0;i--)
    {
       solve(i);
    }
    
    for(int i = 0;i < n;i++)
    {
        char *c = &str[i][0];
        while(*c != '\0')
        {
            cout<<*c;
            c++;
        }
        if(*c == '\0')putchar('\n');
        //putchar('\n');
    }
    
	return 0;
}