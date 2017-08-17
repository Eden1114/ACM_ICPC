/*
 *题号：POJ 2299
 *时间：
 *解题思想：离散化+树状数组
 *
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>

#define F(i,a,b) for(int i = a; i < b; i++)


const double eps = 1e-8;
const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;

#define maxn 500047    
LL c[maxn], a[maxn];
int n;
int Lowbit(int x)  // 2^k  
{
    return x&(-x);
}
void update(int i, int x)//i点增量为x  
{
    while (i <= n)
    {
        c[i] += x;
        i += Lowbit(i);
    }
}
int sum(int x)//区间求和 [1,x]  
{
    int sum = 0;
    while (x>0)
    {
        sum += c[x];
        x -= Lowbit(x);
    }
    return sum;
}

int Getsum(int x1, int x2) //求任意区间和  
{
    return sum(x2) - sum(x1 - 1);
}

struct st
{
    int ord;
    LL v;
}arr[500010];

bool cmp(st a, st b)
{
    return a.v > b.v;
}
int main()
{
    while (rei(n), n)
    {
        ms(c);
        f(i, 1, n)
        {
            int x;
            rei(x);
            arr[i].ord = i;
            arr[i].v = x;
        }
        sort(arr + 1, arr + n + 1,cmp);
        //此处用了离散化
        
        
        f(i, 1, n)
            a[i] = arr[i].ord;
        LL count = 0;
        f(i, 1, n)
        {
            count += sum(a[i]);
            update(a[i], 1);
        }
        printf("%lld\n", count);
    }
    return 0;
}