#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

const int maxn = 10010;
int N,K;
int ans,root,Max;

struct Edge
{
    int v;//当前node
    int next;//下一个node
    int w;//边的权值
};
struct Edge edge[maxn * 2];

int head[maxn];
int size[maxn];//树的大小
int maxv[maxn];//最大孩子节点的size
int vis[maxn];
int dis[maxn];
int num;
int tot;//记录边的个数的迭代变量

//初始化
void init()
{
    tot = 0;
    ans = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
}

//向edge数组中添加边
void add_edge(int u,int v,int w)
{
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    //该边的下一个结点是head[u]
    head[u] = tot++;
}

//处理子树的大小
//处理根
void dfssize(int u, int f)
{
    size[u] = 1;
    maxv[u] = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        dfssize(v, u);
        size[u] += size[v];
        if(size[v] > maxv[u]) 
            maxv[u] = size[v];
    }
}

//找重心 //get_root
void dfsroot(int r,int u,int f)
{
    //size[r]-size[u]是u上面部分的树的尺寸
    //跟u的最大孩子比，找到最大孩子的最小差值节点
    if(size[r] - size[u] > maxv[u])    
        maxv[u]=size[r]-size[u];

    if(maxv[u]<Max) Max=maxv[u],root=u;
    for(int i = head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(v == f || vis[v] )continue;
        dfsroot(r,v,u);
    }
}

//求每个点离重心的距离
void dfsdis(int u,int d,int f)
{
    dis[num++] = d;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != f && !vis[v])
            dfsdis(v, d+edge[i].w, u);
    }
}

//计算以u为根的子树中有多少点对的距离小于等于K
int calc(int u, int d)
{
    int ret = 0;
    num = 0;
    dfsdis(u, d, 0);
    sort(dis, dis + num);
    
    
    int i = 0;
    int j = num - 1;
    int a,b;
    while(i < j)
    {
        if (dis[i] + dis[j] < K) ++i;
        else if (dis[i] + dis[j] > K) --j;
        else if (dis[i] == dis[j]) 
        {
            ret += (j - i) * (j - 1 + 1) / 2;
            break;
        } 
        else 
        {
            a = i; b = j;
            while (dis[a] == dis[i]) ++i;
            while (dis[b] == dis[j]) --j;
            ret += (i - a) * (b - j);
        }
    }
    return ret;
}

//int calc(int u, int d) {
//    int ret = 0, a, b;
//    num = 0;
//    dfs(u, d, 0);
//    sort(dis, dis + c);
//    for (int i = 0, j = c - 1; i < j; )
//        if (dis[i] + dis[j] < k) ++i;
//        else if (dis[i] + dis[j] > k) --j;
//        else if (dis[i] == dis[j]) 
//        {
//            ans += (j - i) * (j - 1 + 1) / 2;
//            break;
//        } 
//        else 
//        {
//            a = i; b = j;
//            while (dis[a] == dis[i]) ++i;
//            while (dis[b] == dis[j]) --j;
//            ans += (i - a) * (b - j);
//        }
//    return ans;
//}


void dfs(int u)
{
    Max = N;
    dfssize(u, 0);
    dfsroot(u, u, 0);
    
    ans += calc(root, 0);
    vis[root] = 1;
    
    for(int i = head[root]; i != -1; i=edge[i].next)
    {
        int v = edge[i].v;
        if(!vis[v])
        {
            ans -= calc(v,edge[i].w);
            dfs(v);
        }
    }
}

void prarray(int a[], int n) {
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<'\t';
    }
    cout<<endl;
}

void pr(struct Edge t[], int n) {
    
    cout<<"v:"<<endl;
    for(int i = 0;i < n;i++)
    {
        cout<<t[i].v<<'\t';
    }
    cout<<endl;
    
    cout<<"next:"<<endl;
    for(int i = 0;i < n;i++)
    {
        cout<<t[i].next<<'\t';
    }
    cout<<endl;
    
    cout<<"w:"<<endl;
    for(int i = 0;i < n;i++)
    {
        cout<<t[i].w<<'\t';
    }
    cout<<endl;
    
}


int main()
{
    while(scanf("%d", &N) != EOF && N)
    {
        init();
        int v,w;
        for(int u = 1;u <= N;u++)
        {
            while (scanf("%d", &v) && v)
            {
                scanf("%d",&w);
                add_edge(u, v, w);
                add_edge(v, u, w);
            }
        }
        
//        pr(edge, tot);
//        prarray(head, tot);
//        
        while(scanf("%d", &K) && K)
        {
            memset(vis, 0, sizeof(vis));
            ans = 0;
            dfs(1);
            if(ans == 0)
            {
                puts("NAY");
                //printf("%d",ans);
            }
            else {
                //printf("%d",ans);
                puts("AYE");
            }
        }
        puts(".");
    }
    return 0;
}