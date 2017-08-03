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
char s[80+5];
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
    int n;scanf("%d",&n);
    for(int _ = 0;_ < n;_++)
    {
        scanf("%s",s);
        char *t = s;
        double mass = 0;
        while(*t != '\0')
        {
            if(*t == 'C')
            {
                if(*(t+1) >= '0' && *(t+1)<='9' )
                {
                    if(*(t+2) >= '0' && *(t+2)<='9')
                    {
                        mass += 12.01 *  (( *(t+1) - '0')*10 + *(t+2)-'0');
                        t += 3;
                    }
                    else
                    {
                        
                        mass += 12.01 *(*(t+1) -'0');
                        t +=2;
                    }
                }
                else
                {
                    mass += 12.01;
                    t++;    
                }
            }
            else if(*t == 'H' )
            {
                if(*(t+1) >= '0' && *(t+1)<='9' )
                {
                    if(*(t+2) >= '0' && *(t+2)<='9')
                    {
                        mass += 1.008 *  (( *(t+1) - '0')*10 + *(t+2)-'0');
                        t += 3;
                    }
                    else
                    {
                        
                        mass += 1.008 *(*(t+1) -'0');
                        t +=2;
                    }
                }
                else
                {
                    mass += 1.008;
                    t++;    
                }
            }
            else if( *t == 'O' )
            {
                if(*(t+1) >= '0' && *(t+1)<='9' )
                {
                    if(*(t+2) >= '0' && *(t+2)<='9')
                    {
                        mass += 16.00 *  (( *(t+1) - '0')*10 + *(t+2)-'0');
                        t += 3;
                    }
                    else
                    {
                        
                        mass += 16.00 *(*(t+1) -'0');
                        t +=2;
                    }
                }
                else
                {
                    mass += 16.00;
                    t++;    
                }
            }
            else if(*t == 'N')
            {
                if(*(t+1) >= '0' && *(t+1)<= '9')
                {
                    if(*(t+2) >= '0' && *(t+2)<= '9')
                    {
                        mass += 14.01 *  (( *(t+1) - '0')*10 + *(t+2)-'0');
                        t += 3;
                    }
                    else
                    {
                        
                        mass += 14.01 *(*(t+1) -'0');
                        t +=2;
                    }
                }
                else
                {
                    mass += 14.01;
                    t++;    
                }
            }
        }
        printf("%.3lf\n",mass);
    }
	return 0;
}