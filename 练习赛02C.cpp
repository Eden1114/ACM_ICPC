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

const int maxn=1e5 + 5;
vector<int>num[maxn];
int result[maxn];
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; i++)
    {
        num[i].push_back(0);
        int temp;
        for(int j=1; j<=M; j++)
        {
            scanf("%d",&temp);
            num[i].push_back(temp);
        }
    }

    for(int j = 1; j <= M; j++)
    {
        int i = 1;
        while(i < N)
        {
            if(num[ i + 1][j] >= num[i][j])
            {
                int flag = i;
                while(flag < N && num[flag + 1][j] >= num[flag][j])
                    flag++;
                for(int k = i; k < flag; k++)
                    num[k][j] = flag;
                i = flag;
            }
            else
            {
                num[i][j] = i;
                i++;
            }
        }
    }

    memset(result,0,sizeof(result));
    result[N]=N;//最后一行特判
    
    for(int  i = 1; i < N; i++)
    {
        int max_result=num[i][1];
        for(int j=2; j<=M; j++)
            max_result=max(max_result,num[i][j]);
        result[i]=max_result;
    }

    int T;
    scanf("%d",&T);
    
    
    
    while(T--)
    {
        int L,R;
        scanf("%d%d",&L,&R);
        if(R<=result[L])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}