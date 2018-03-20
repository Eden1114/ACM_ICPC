long long
using namespace std;

const long long maxn = 1000050;

struct SuffixArray
{
    long long s[maxn];      // 原始字符数组（最后一个字符应必须是0，而前面的字符必须非0）
    long long sa[maxn];     // 后缀数组
    long long rank[maxn];   // 名次数组. rank[0]一定是n-1，即最后一个字符
    long long height[maxn]; // height数组
    long long t[maxn], t2[maxn], c[maxn]; //辅助数组
    long long n; // 字符个数
    
    void clear()
    {
        n = 0;
        memset(sa, 0, sizeof(sa));
    }
    
    // m为最大字符值加1。调用之前需设置好s和n
    void build_sa(long long m)
    {
        long long i, *x = t, *y = t2;
        for(i = 0; i < m; i++) c[i] = 0;
        for(i = 0; i < n; i++) c[x[i] = s[i]]++;
        for(i = 1; i < m; i++) c[i] += c[i-1];
        for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(long long k = 1; k <= n; k <<= 1)
        {
            long long p = 0;
            for(i = n-k; i < n; i++) y[p++] = i;
            for(i = 0; i < n; i++) if(sa[i] >= k) y[p++] = sa[i]-k;
            
            for(i = 0; i < m; i++) c[i] = 0;
            for(i = 0; i < n; i++) c[x[y[i]]]++;
            for(i = 1; i < m; i++) c[i] += c[i-1];
            for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
            
            swap(x, y);
            p = 1;
            x[sa[0]] = 0;
            for(i = 1; i < n; i++)
                x[sa[i]] = y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k] ? p-1 : p++;
            if(p >= n) break;
            m = p;
        }
    }
    
    void build_height()
    {
        long long k = 0;
        for(long long i = 0; i < n; i++) rank[sa[i]] = i;
        for(long long i = 0; i < n; i++)
        {
            if(k) k--;
            long long j = sa[rank[i]-1];
            while(s[i+k] == s[j+k]) k++;
            height[rank[i]] = k;
        }
    }
};

SuffixArray sa;
char ch[maxn];
char s1[maxn];
char s2[maxn];


void solve(long long len1,long long len2){
    long long ans = 0,l,r;
    for(long long i = 1; i <= sa.n; i++) {
        if(sa.height[i] > ans) {
            l = sa.sa[i - 1];
            r = sa.sa[i];
            if(l + sa.height[i] - 1 < len1 && r > len1) ans = max(ans, sa.height[i]);
            if(r + sa.height[i] - 1 < len1 && l > len1 )ans = max(ans, sa.height[i]);
        }
    }
    printf("%d\n",ans);
}

int main()
{
    while(~scanf("%s", s1))
    {
        sa.clear();
        scanf("%s", s2);
        unsigned long len1 = strlen(s1);
        unsigned long len2 = strlen(s2);
        unsigned long len;
        
        for(int i = 0; i < len1; i++) {
            ch[i] = s1[i];
        }
        
        ch[len1] = 1;
        
        for(int i = 0; i < len2; i++) {
            ch[i + len1 + 1] = s2[i];
        }
        
        len = len1 + len2 + 1;
        
        ch[len] = 0;
        
        sa.n = len;
        
        for(int i = 0; i < len; i ++)
        {
            sa.s[i] = ch[i] - 'a' + 1;
        }
        sa.s[len] = 0;
        sa.build_sa(30);
        sa.build_height();
        
        solve(len1,len2);
    }
}
