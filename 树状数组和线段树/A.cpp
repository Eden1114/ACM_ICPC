/*
 *题号：
 *时间：
 *解题思想：线段树
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
const int maxn = 50010;

struct node {
    int l,r,v;
} a[maxn << 2];
//完全二叉树用数组实现

void PhosUp(int root)
{
    a[root].v = a[root << 1].v + a[root << 1 | 1].v;
    //root‘s value is the sum of its children.
    //位运算实现除以二，和除以二加一，更快！
}

void build_tree(int l,int r,int root)
{
    a[root].l = l;
    a[root].r = r;
    a[root].v = 0;
    
    if (l == r) {
        scanf("%d",&a[root].v);
        return;
    }
    //如果是单个结点的话，添加该点的值

    int mid = (l + r) >> 1;
    build_tree(l, mid, root << 1);
    build_tree(mid + 1, r, root << 1 | 1);
    PhosUp(root);
    //递归建树
    //按照左右子树的递归建立，再一次返回根节点的值
    //线段树的叶子节点就是每个营地的人数
    //线段树的根就是他的左右子树的和
}

void update(int l,int r,int root, int k)
{
    if(a[root].l == l & a[root].r == r)
    {
        a[root].v += k;
        return;
    }
    
    int mid = (a[root].l + a[root].r) >> 1;
    
    if (r <= mid) update(l, r, root << 1, k);
    //区间在左半边
    
    else if(l > mid) update(l, r, root << 1 | 1, k);
    //区间在右半边
    
    else 
    {
        update(l, mid, root << 1, k);
        update(mid + 1, r, root << 1 | 1, k);
    }
    //区间跨越左右半边（中点在区间内）
    
    PhosUp(root);
    //更新完以后，递归修改树
}

int Query(int l, int r, int root)
{
    if(a[root].l == l && a[root].r == r)
    {
        return a[root].v;
    }
    //查询到了某一个叶子节点
    
    int mid = (a[root].l + a[root].r) >> 1;
    
    int ans = 0;
    
    if(r <= mid) ans += Query(l, r, root << 1);
    else if(l > mid) ans += Query(l, r, root << 1 | 1);
    else {
        ans += Query(l, mid, root << 1) + Query(mid + 1, r, root<< 1 | 1);
    }
    return ans;
}


int main(/*int argc, char *argv[]*/) {
	int T;scanf("%d",&T);
    char ch[10];
    int c = 1, l, r,n;
    while(T--)
    {
        scanf("%d",&n);
        printf("Case %d:\n", c++);
        build_tree(1, n, 1);
        while(1)
        {
            scanf("%s",ch);
            if(ch[0] == 'E')
            {
                break;
            }
            if(ch[0] == 'Q')
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",Query(l, r, 1));
            }
            if(ch[0] == 'A')
            {
                scanf("%d%d", &l, &r);
                update(l, l, 1, r);
            }
            if(ch[0] == 'S')
            {
                scanf("%d%d", &l, &r);
                update(l , l, 1, -r);
            }
        }
    }
	return 0;
}