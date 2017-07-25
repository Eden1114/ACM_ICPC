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

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	long long n,k;
    cin>>n>>k;
    long long res = n / k;
    if(res % 2)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
	return 0;
}