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
int n,m,k;  
int main()  
{  
    int i,j,temp,flag=0,count,chong,nochong;  
    cin>>n>>m;  
    set<int> s;  
    while(m--)  
    {  
        count=0;  
        chong=0;  
        nochong=0;  
        s.clear();  
        set<int>::iterator it;  
        cin>>k;  
        if(k==1)  
        {  
            flag=1;  
        }  
        for(i=0;i<k;i++)  
        {  
            scanf("%d",&temp);  
            it=s.find(temp);  
            if(it!=s.end())  
            {  
                chong++;  
                continue;  
            }  
            it=s.find(-1*temp);  
            if(it!=s.end())  
            {  
                count++; //情侣加一   
            }  
            else  
            {  
                s.insert(temp);  
                nochong++;  
            }  
        }   
        if(nochong==k || nochong+chong==k) //后边这个判断要小心，不要忘  
        {  
            flag=1;  
        }  
    }  
    if(flag==1 )  
    {  
        printf("YES\n");  
    }  
    else  
    {  
        printf("NO\n");  
    }  
    return 0;  
 }  