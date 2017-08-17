/*
 *题号：
 *时间：
 *解题思想：字典树
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

char s[12];

class Tree
{
public:
    int num;
    Tree *next[27];
    
    Tree()
    {
        num = 0;
        for(int i = 0;i < 27;i++)
        {
            next[i] = NULL;
        }
    }
};
class Tree *root = new Tree();
//对定义树的结构和构造函数

void insert(Tree *p,char *s)
{
    int i = 0;
    while(s[i])
    {
        int x = s[i] -'a';
        
        if(p->next[x] == NULL)
        {
            p->next[x] = new Tree();
        }
        p = p->next[x];
        p->num++;
        i++;
    }
}


int query(Tree *p,char *s)
{
    int i = 0;
    int res= 0;
    while(s[i])
    {
        int x = s[i] - 'a';
        if(p->next[x] == NULL)
            return 0;
        p = p->next[x];
        res = p->num;
        i++;
    }
    return res;
}
//插入操作

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	while(gets(s) && s[0])
    {
        insert(root,s);
    }
    while(gets(s))
    {
        printf("%d\n",query(root,s));
    }
    
	return 0;
}