/*
 *题号：
 *时间：
 *解题思想：
 *
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

const int maxn = 1e5 + 5;

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	
    int n;double a;
    cin>>n>>a;

    double min = 1e9;
    int min_i = -1;
    
    double res;
    double temp;
    for(int i = 1;i <= n - 2;i++)
    {
        temp = 180.0/n * i;
        res = abs(temp - a);
        if(res <= min) {min = res;min_i = i;}
    }
    
    cout<<"2 1 "<<min_i+2<<endl;
    return 0;
}