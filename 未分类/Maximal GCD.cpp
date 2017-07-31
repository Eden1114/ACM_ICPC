/*
A - Maximal GCD CodeForces - 803C
*/
#include<stdio.h>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
long long int q[200005];  
long long int w[100005];  
int main()  
{  
    long long int n,k;  
    scanf("%lld%lld",&n,&k);  
    if(k*(k+1)/2>n||k>200005)
    //比如这组数据1 4000000000 还是会爆ll 所以如果k>2e5直接就输出-1了   
    {  
        printf("-1\n");  
        return 0;  
    }  
    int x=0;    //因子个数   
    for(int i=1;i<=sqrt(n);i++)  
    //最开始用的i*i<n 但是i*i可能会大于int 然后re了一发   
    {  
        if(n%i==0)  
        {  
            x++;  
            w[x]=i;  
            x++;  
            w[x]=n/i;      //比如24 2输出的8 16 gcd为8 >sqrt(24)   
        }  
    }  
    sort(w+1,w+1+x);
    bool flag = false;
    
    for(int i=1;i<=x;i++)  
    {  
        long long int sum=k*(k-1)*w[i]/2;  
        long long int ed=n-sum;     
        //前k-1个数为 i 2i 3i ....(k-1)i 最后一个数就为n-他们的和   
        if(ed>(k-1)*w[i]&&ed%w[i]==0)  
        //判断这个gcd为i的数列合法么 如果合法就跟新数组   
        {  
            flag = true;  
            for(int j=1;j<=k-1;j++)  
                q[j]=j*w[i];  
            q[k]=ed;  
        }  
        else if(ed<=(k-1)*w[i])  
        break;  
    }
    
    if(flag)  
    {  
        for(int i=1;i<=k;i++)  
        {  
            if(i!=k)  
            printf("%lld ",q[i]);  
            else  
            printf("%lld\n",q[i]);  
        }  
    }  
    else  printf("-1\n");  
    return 0;  
}  