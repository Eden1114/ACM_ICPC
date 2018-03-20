#include <cstdio>
#include <algorithm>
#include <cstring>
const int maxn = 100005;

void add(int a, int b, int c) {
    v[++cnt] = b;
    w[cnt] = c;
    p[cnt] = h[a];
    h[a] = cnt;
}

void root(int x,int fa) {
    sz[x] = 1;
    g[x] = 0;
    for(int i = h[x];i;i = p[i]) {
        if(v[i] != fa && !vis[i]) {
            root(v[i], x);
            sz[x] += sz[v[i]];
            g[x] = max(g[x], sz[v[i]]);
        }
    }
    g[x] = max(g[x], node - sz[x]);
    if(g[x] < g[rt]) rt = x;

}


int getRoot(int x, int fa, int sz) {
    rt = 0;
    node = sz;
    g[0] = inf;
    root(x, fa);
    return rt;
}


void dfs(int x, int d, int fa) {
    dis[c++] = d;
    adj(i, x)dfs(v[i], d + w[i],x);


}
