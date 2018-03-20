#include <bits/stdc++.h>  
using namespace std;  
const int N=2e6+20;

struct node{  
    int l,r,sum;  
    //sum:前缀i内:下标l~r不同的数的个数   
}T[N*40];  

int x,y,n,m,a[N],last[N];  

int cnt,root[N];//cnt是根节点

//初始化一颗线段树
int build(int l,int r)
{  
    int rt=++cnt;
    T[rt].sum = T[rt].l = T[rt].r = 0;
    if(l == r) return rt;
    int mid = (l+r)>>1;  
    T[rt].l = build(l,mid);  
    T[rt].r = build(m+1,r);  
    return rt;
}


//update(1,n,root[i],root[i-1],1,i);
//update(1,n,root[i],root[i-1],-1,last[v]);  
//update(1,n,root[i],root[i],1,i);
void update(int l,int r,int &x,int y,int v,int pos)
{
    T[++cnt]=T[y];
    T[cnt].sum += v;
    x = cnt;
    if(l == r) return;
    int m=(l + r) >> 1;
    if(m >= pos) update(l,m,T[x].l,T[y].l,v,pos);
    else update(m+1,r,T[x].r,T[y].r,v,pos);
}

int query(int l,int r,int c,int pos)  
{  
    if(l==r) return T[c].sum;  
    int m=(l+r)>>1;  
    if(m>=pos)  
    return T[T[c].r].sum+query(l,m,T[c].l,pos);  
    else  
    return query(m+1,r,T[c].r,pos);  
}

    void init()
{
    cnt = 0;
    memset(last, 1, sizeof(last));
}

int main()  
{  
    while(cin>>n)  
    {  
        init();
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);    
        
        root[0]=build(1,n);
        
        for(int i=1;i<=n;i++)
        {  
            int v = a[i];  
            if(last[v] == -1)
                update(1,n,root[i],root[i-1],1,i);
            else  
            {  
                update(1,n,root[i],root[i-1],-1,last[v]);
                update(1,n,root[i],root[i],1,i);
            }
            last[v]=i;//标记最后一次出现数字a[i]的下标，初始值是-1  
        }
          
        cin>>m;  
        for(int i = 0;i < m;i++)  
        {  
            scanf("%d%d",&x,&y);  
            int ans = query(1,n,root[y],x);
            printf("%d\n",ans);  
        }  
    }  
    return 0;     
}   