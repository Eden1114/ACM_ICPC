/*
Greedy:
    We should find the most effective standard
to greed the answer.
    To do that, We can find some math formulation
from the easy case.
    Just like the way we use some special value 
in math exam.
    In this problem, compare function is the most
important module.
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct cow{
    long long t;
    long long d;
} cows[100010];

long long sum[100010];

int compare(struct cow a,struct cow b)
{
    return (1.0 * a.t / a.d)<(1.0 * b.t / b.d);
}

int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n;
    
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            scanf("%lld%lld",&cows[i].t,&cows[i].d);
        }
        sort(cows,cows+n,compare);
        
        sum[n - 1] = 0;
        
        for(int i = n - 2;i >= 0;i--)
        {
            sum[i] = sum[i+1] + cows[i+1].d;
        }
        long long ans = 0;
        for(int i = 0; i < n; i++)
            ans += 2*cows[i].t*sum[i];
        printf("%lld\n",ans);
    }
    return 0;
}