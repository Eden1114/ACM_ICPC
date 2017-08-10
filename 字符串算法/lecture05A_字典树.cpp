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
/*
不幸的是注释的代码TLE了
struct Tree
{
    int num;
    Tree *next[10];
    Tree()
    {
        num = 0;
        for(int i = 0;i < 10;i++)
        {
            next[i] = NULL;
        }
    }
} *root;
//对定义树的结构和构造函数

int insert(Tree *p,char *s)
{
    int i = 0;
    while(s[i])
    {
        int x = s[i] -'0';
        if(p->next[x] == NULL)
        {
            p->next[x] = new Tree();
        }
        p = p->next[x];
        i++;
    }
    p->num++;
    return (p->num);
}
//插入操作



//在算法竞赛里，自己实现一个类（数据结构）
//的时候，不需要设计太多权限，结构的问题。
//尽量减轻代码量

*/
/*
int main() {
	//ios::sync_with_stdio(false);
	char s[30],s1[30];
    int n,maxs,stl,i,len;
    while(cin>>n)
    {
        root = new Tree();
        maxs = -5;
        while(n--)
        {
            cin>>s;
            stl = strlen(s);
            i = len = 0;
            for(int i = 0;i < stl;i++)
            {
                if(s[i] != '0')
                {
                    break;
                }
            }
            
            for(i;i < stl;i++)
            {
                s1[len++] = s[i];
            }
            s1[len] = '\0';
            maxs = max(maxs,insert(root, s1));
        }
        cout<<maxs<<endl;
    }
	return 0;
}
*/

const int M = 3005;
int f[M];

int main(){
    int man,mx;
    int n;
    while(scanf("%d",&n) != EOF && n)
    {
        man = mx = 1;
        memset(f,0,sizeof(f));
        for(int i = 0;i < n;i++)
            scanf("%d",&f[i]);
        sort(f,f+n);
        for(int i = 1;i < n;i++)
        {
            if(f[i] > f[i-1])
                man = 1;
            else
            {
                man++;
                mx =max(mx,man);
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}

