#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100000 + 5;

vector<int> node[N << 2];

int T, n, q, ql, qr, ans, k, sz;

int a[N], b[N];//用来存读入的数组

void Build(int o, int l, int r) {
    node[o].clear();
    if(l == r){
        node[o].push_back(a[l]);
        return ;
    }
    int m = (l + r) >> 1;
    Build(o << 1, l, m);
    Build(o << 1|1, m + 1, r);
    node[o].resize(r - l + 1);
    merge(node[o<<1].begin(), node[o<<1].end(), node[o<<1|1].begin(), node[o<<1|1].end(), node[o].begin());
}

int query(int o, int l, int r, int x){
    if(ql <= l && qr >= r)  return upper_bound(node[o].begin(), node[o].end(), x) - node[o].begin();
    int m = (l + r) >> 1;
    int ret = 0;
    if(ql <= m)ret += query(o << 1, l, m, x);
    if(qr > m)ret += query(o << 1|1, m + 1, r, x);
    return ret;
}

void work(){
    scanf("%d%d%d", &ql, &qr, &k);
    int lt = 1, rt = sz;
    while(lt <= rt){
        int md = (lt + rt) >> 1;
        if(query(1, 1, n, b[md]) >= k)rt = md - 1;
        else lt = md + 1;
    } 
    printf("%d\n", b[rt+1]);
}

int main() {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        Build(1, 1, n);
        sort(b + 1, b + n + 1);
        sz = unique(b + 1, b + n + 1) - (b + 1);
        
        //处理询问
        while(q --)
            work();
    
    return 0;
}