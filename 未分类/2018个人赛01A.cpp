/**
枚举+二分
*/

const int N = 1e5 + 5;
struct node
{
    int val,id;
}a[N];
long long s[N];

int n,A,cf,cm;
long long m;

bool cmp1(node a,node b)
{
    return a.val<b.val;
}

bool cmp2(node a,node b) 
{
    return a.id<b.id;
}

int main()
{
    
    while(~scanf("%d%d%d%d%lld",&n,&A,&cf,&cm,&m)) {
        for(int i = 0;i < n;++i) {
            scanf("%d",&a[i].val);
            a[i].id=i;
        }
        sort(a,a+n,cmp1);
        
        s[0]=0;
        
        for(i = 0; i < n; ++i) {
            s[i+1] = s[i] + a[i].val;
        }
        //技能所有的val的前缀和
        
        long long ans = -1,ansi,ansj,ansmin;
        long long cost,tmp,tmin,left;
        for(int i = 0,j = 0;i <= n;++i) {
            cost = (long long) A * (n-i) - (s[n]-s[i]);
            //升n-i个满级的cost
            if(cost > m) continue;//不够用
            tmp = (n-i) * cf; //获得的战力
            left = m - cost;  //剩余的技能点
            
            while(j < i && (long long)(a[j].val * j)-s[j]<= left) j++;
            //判断{a[0].val,...,a[j-1].val}这j个值加上剩余价值left，能否达到a[j].val
            //如果可以达到，则{0,...,j-1，j},共(j+1)个值至少为a[j].val;
            
            if(j == 0) tmin = A;
            else tmin = min((left+s[j])/j,(LL)A);
            //tmin就是最低等级的那个
            
            tmp += (LL)tmin * cm;
            //tmp是局部的解
            if(ans < tmp){
                ans = tmp;
                ansi = i;
                ansj = j-1;
                ansmin = tmin;
            }
        }
        
        for(int i = ansi; i < n; i++) {
            a[i].val = A;
        }
        for(int i = 0; i <= ansj; i++) {
            a[i].val = ansmin;
        }
        sort(a, a + n, cmp2);
        
        cout << ans << endl;
        for(int i = 0; i < n;++i){
            printf("%d ",a[i].val);
        }
        putchar('\n');
    }
    return 0;
}
