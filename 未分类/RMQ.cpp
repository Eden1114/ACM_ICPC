const int MAX_N = 1 << 17;
int n;
int dat[2 *MAX_N - 1];

void init(int n_) {
    //为了便于实现，把元素个数扩展到2^n的形式
    n = 1;
    while(n < n_) n <<= 1;
    for(int i = 0;i < 2 * n - 1;;i++)
    {
        dat[i] = INT_MAX; //初始化的值应该做到对操作无影响
    }
}

//把第k个值设为a
void update(int k, int a) {
    //叶子结点
    k += n - 1;
    dat[k] = a;
    //向上更新
    while(k > 0) {
        k = k / 2;
        dat[k] = min(dat[2 * k], dat[2 * k + 1]);
    }
}

//求[a,b)的最小值
//k是节点编号，l,r表示这个节点对应的是[l,r)区间
//在外部调用时，用query(a, b, 0, 0, n)
int query(int a, int b, int k, int l, int r) {
    if(a >= r || b <= l) return INT_MAX;
    int (a <= l && r <= b) return dat[k];
    else {
        int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
}