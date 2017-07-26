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

const int maxn = 1e5 + 5;
char g[30];
char patern[maxn];
char str[maxn];
int n;
int star = -1;
//*的index
set<char> good;

int main(/*int argc, char *argv[]*/) {
	scanf("%s",g);
    scanf("%s",patern);
    scanf("%d",&n);
    
    char *t;
    t = g;
    while(*t != '\0'){good.insert(*t);t++;}
    t = patern;
    while(*t != '\0'){if(*t == '*'){star = t - patern;break;};t++;}
    for(int i = 0;i < n;i++)
    {
        bool flag = true;
        scanf("%s",str);
        if(star == -1)
        {
            char *pl = patern,*sl = str;
            if(strlen(str) > strlen(patern))
            {
                cout<<"NO"<<endl;
                continue;
            }
            else
            while(*pl != '\0')
            {
                if(*pl != *sl)
                {
                    if(*pl == '?')
                    {
                        if(good.count(*sl) == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else 
                    {
                        flag = false;
                        break;
                    }
                }
                pl++;
                sl++;
            }
            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        
        else
        {
            bool flag = true;
            char *pl = patern,*pr = patern + strlen(patern);
            char *sl = str,*sr = str + strlen(str);
            
            while(*pl != '*' && *pl != '\0')
            {
                if(*pl != *sl)
                {
                    if(*pl == '?')
                    {
                        if(good.count(*sl) == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else 
                    {
                        flag = false;
                        break;
                    }
                }
                pl++;
                sl++;
            }
            if(flag == false){cout<<"NO"<<endl;continue;}
            
            while(*pr != '*' && pr != patern)
            {
                if(*pr != *sr)
                {
                    if(*pr == '?')
                    {
                        if(good.count(*sr) == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    else 
                    {
                        flag = false;
                        break;
                    }
                }
                pr--;
                sr--;
            }
            
            if(flag == false){cout<<"NO"<<endl;continue;}
            
            //cout<<sl -str<<"_"<<sr -str<<endl;
            if(sr == sl - 1)//*为空
            {
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                continue;
            }
            
            else
            {
                char *it = sl;
                //while(it != sr + 1)
                for(;it  - 1 != sr;it++)
                {
                    if(good.count(*it) == 1) {flag = false;break;}
                    
                }
                if(flag) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                continue;
            }
        }
    }
	return 0;
}