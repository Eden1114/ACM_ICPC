/*
 *题号：HDU1551 cable master
 *时间：2017年07月25日
 *解题思想：二分答案
 *注意：
 *二分答案模板：
 *while(right - left > eps)
 *{
 *    double mid = (right + left)/2.0;
 *    if(check(mid))
 *    {
 *        left = mid;
 *    }
 *    else right = mid;
 *}
 *check()函数是重点，根据题意来写。
 *二分答案适合不方便解出来，但是答案满足在一个区间内单调。
 *通过二分的思想，不断的接近答案
 */
//include <bits/stdc++.h>
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

#define F(i,a,b) for(int i = a; i < b; i++)

using namespace std;

const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

	int n,k;
    double cable[maxn];
    double sum = 0;
    
bool check(double mid)
{
    int ans = 0;
    for(int i = 0; i < n;i++)
    {
        ans += (int)(cable[i]/mid);
    }
    if(ans >= k) return true;
    else return false;
}

int main(/*int argc, char *argv[]*/) {
	cin>>n>>k;
    for(int i = 0; i < n;i++)
    {
        cin>>cable[i];
    }
    sort(cable,cable+n);
    double left = 0,right = cable[n-1];
    
    while(right - left > 1e-9)
    {
        double mid = (right + left)/2.0;
        if(check(mid))
        {
            left = mid;
        }
        else right = mid;
    }
    
    int temp = 100*left;
    double ans = temp*0.01;
    printf("%.2lf\n",ans);
    return 0;
}