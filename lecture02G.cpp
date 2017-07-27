/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>

#include <cmath>
#include <map>
#include <set>



const double eps = 1e-8;
const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;


const int maxn = 750 + 5;
int a[maxn][maxn];
int b[maxn];
int main(/*int argc, char *argv[]*/) {
	int n;
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0; i < n;i++)
            for(int j = 0; j < n;j++)
                scanf("%d",&a[i][j]);
        
        int small = 0;
        
        for(int i = 0;i < n;i++)
        {
            sort(*(a+i),*(a+i)+n);
            small += a[i][0];
        }
        
        
        
        while(n != 0)
        {
            cout<<small;
            for(int i = 0;)
            a[i][maxn] = 
            if(n != 1) cout<<' ';
            n--;
        }
        cout<<endl;
    }	
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=760;
int A[maxn][maxn];

typedef struct node
{
        int sum,index;  ///保留a[i]+b[index]的值和b[]的下标
        node(int s,int i)
        {
                    sum=s; index=i;
        }
        bool operator < (const node& n1) const{
                 return sum>n1.sum;
        }
}P;
P p1(0,0);
int n;

void Merge(int *a,int *b,int *c)///对a,b两个数组求前n个最小值
{ ///使用的是多路归并的思想
            priority_queue<P>q;
            for(int i=0;i<n;i++)
                    q.push(node(a[i]+b[0],0));
            for(int i=0;i<n;i++)
            {
                     p1=q.top(); q.pop();  ///取出最小的一个值
                     c[i]=p1.sum;
                     int j=p1.index;
                     if(j+1<n)   ///将目前最小值列的下一个值放入优先队列
                             q.push(node(p1.sum-b[j]+b[j+1],j+1));
            }
}

int main()
{
            freopen("in.txt","r",stdin);
            while(scanf("%d",&n)!=EOF)
            {
                        for(int i=0;i<n;i++)
                        {
                                 for(int j=0;j<n;j++)
                                            scanf("%d",&A[i][j]);
                                 sort(A[i],A[i]+n);
                        }
                     for(int i=1;i<n;i++)
                                Merge(A[0],A[i],A[0]);
                        printf("%d",A[0][0]);
                        for(int i=1;i<n;i++)
                                printf(" %d",A[0][i]);
                        printf("\n");
            }
    return 0;
}
*/