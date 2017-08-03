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
char str[104];  
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false); 
    int n; 
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s",str); 
        int len = strlen(str);  
        for (int i = 1 ; i <= len ; i++)
        {
            if (len % i == 0)
            { 
                int k;
                for (k = i ; k < len ; k++) 
                {      
                    if (str[k] != str[k%i]) break; 
                }
                
                if (k == len)
                { 
                    printf("%d\n",i);
                    break;
                } 
            }
        }
        if(n) putchar('\n');
    }
    return 0;  
}