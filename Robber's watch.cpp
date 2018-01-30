#include <iostream>
#include <cstdio>
using namespace std;
/*
 给两个整数m,n（十进制）
 表示一天有m个小时，1小时n分钟
 然后用7进制的一对数字表示时间
 使得表示的数字各不相同
 */
int ans = 0;
int l1,l2,l,m,n;
int length(int n)
{
    int result = 0;
    if(n == 0 ) return 1;
    while (n)
    {
        n /= 7;
        result++;
    }
    return result;
}
int value_in_seven_base1(int a[]){
    int sum;
    sum = 0;
    for(int i = 0; i < l1;i++)
        sum = sum*7+a[i];
    return sum;
}
//计算数组中0到l1表示7进制数字的大小
int value_in_seven_base2(int a[]){
    int sum;
    sum = 0;
    for(int i = l1; i < l;i++)
        sum = sum*7+a[i];
    return sum;
}
//计算数组中l1到l2表示7进制数字的大小
bool isRight(int f,int a[]){
    if (a == NULL) return true;
    for(int i = 0;i < f;i++)
        if(a[f] == a[i]) return false;
    if(value_in_seven_base1(a)> m)
    {
        return false;
    }
    if(value_in_seven_base2(a)> n)
    {
        return false;
    }
    return true;
}
void dfs2(int f,int a[]){
    if(f > l - 1) return;
    //边界return
    if(f < l - 1)
    {
        for(int i = 0;i < 7;i++)
        {
            a[f] = i;
            if(isRight(f, a) == false) continue;
            dfs2(f+1,a);
        }
    }
    if(f == l - 1)
    {
        if(isRight(f,a) == true) ans++;
    }
}
void dfs1(int f = 0){
    int a[l];
    memset(a, 0, sizeof(a));
    for (int i = 0;i < 7;i++){
        a[0] = i;
        if(isRight(f,a) == false) continue;
        dfs2(f+1,a);
    }
}
int main(){
    scanf("%d%d",&m,&n);
    l1 = length(m);
    l2 = length(n);
    l = l1 + l2;
    dfs1();
    printf("%d\n",ans);
    return 0;
}


#include <iostream>
#include <cstdio>
int ans = 0;
long long l1,l2,m,n;
using namespace::std;
long long length(long long n);
/*
 给两个整数m,n（十进制）
 表示一天有m个小时，1小时n分钟
 然后用7进制的一对数字表示时间
 使得表示的数字各不相同
 */
int value_seven_base(int a[],int length);
bool isRight1(int a[],int length);
void dfs1(int *a,int *b,int i);
//;
void dfs2(int *a,int *b,int i);
//
int main(){
    cin>>m>>n;
    l1 = length(m);
    l2 = length(n);
    int a1[l1];
    int a2[l2];
    memset(a1,0, sizeof(int)*l1);
    memset(a2,0,sizeof(int)*l2);
    dfs1(a1,a2,0);
    cout<<ans<<endl;
    return 0;
}
long long length(long long n){
    long long result = 0;
    if (n == 0) return 1;
    while(n){
        n /= 7;
        result++;
    }
    return result;
}
bool isRight1(int a[],int length){
    if(value_seven_base(a, length)>m) return 0;
    for(int i = 0; i < length;i++)
        if(a[i] == a[length]) return 0;
    return 1;
}
bool isRight2(int a[],int b[],int length){
    if(value_seven_base(a, length)>n) return 0;
    for(int i = 0; i < length;i++)
        if(a[i] == a[length]) return 0;
    for(int i = 0;i < l2;i++)
        if(b[i] == a[length]) return 0;
    return 1;
}
int value_seven_base(int a[],int length){
    int sum = 0;
    for(int i = 0;i < length;i++)
        sum = sum*7+a[i];
    return sum;
}
void dfs1(int *a,int *b,int i){
    if (i > l1 - 1 || i < 0) return;
    for(int j = 0;j < 7;j++){
        a[i] = j;
        if(isRight1(a,i)) {
            if( i == l1 - 1) dfs2(a,b,0);
            else dfs1(a,b,i + 1);
        }
    }
}
void dfs2(int *a,int *b,int i){
    if(i > l2 - 1 || i < 0) return;
    for(int j = 0; j < 7; j++){
        b[i] = j;
        if(isRight2(a, b, i)){
            if(i == l2 - 1) ans++;
            else(dfs2(a,b,i+1));
        }
    }
}