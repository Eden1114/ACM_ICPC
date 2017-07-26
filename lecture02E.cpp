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

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	
    int n;
    while(~scanf("%d",&n))
	{
        stack <int> s;
        queue <int> q;
        priority_queue<int> pq;
        int read,pattern;
        int flag_stack = true;
        int flag_queue = true;
        int flag_p_queue = true;
        for(int i = 0; i < n;i++)
        {
            
            scanf("%d",&pattern);
            scanf("%d",&read);
            
            if(pattern == 1)
            {
                s.push(read);
                q.push(read);
                pq.push(read);
            }
            else
            {
                if(s.empty() || s.top() != read)
                    flag_stack = false;
                if(q.empty() || q.front() != read)
                    flag_queue = false;
                if(pq.empty() || pq.top() != read)
                    flag_p_queue = false;
                if(!s.empty())
                {
                    s.pop();
                }    
                if(!q.empty())
                {
                    q.pop();
                }
                if(!pq.empty())
                {
                    pq.pop();
                }
            }
        }
        
        
        if(flag_stack && !flag_queue && !flag_p_queue)
        {
            cout<<"stack"<<endl;
        }
        
        else if(!flag_stack && flag_queue && !flag_p_queue)
        {
            cout<<"queue"<<endl;
        }
        else if(!flag_stack && !flag_queue && flag_p_queue)
        {
            cout<<"priority queue"<<endl;
        }
        else if(!flag_stack && !flag_queue && !flag_p_queue)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<"not sure"<<endl;
        }
        
    }
    return 0;
}