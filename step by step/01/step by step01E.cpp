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
int su(int i)
{
    int sum = 0;
    while(i)
    {
        sum += i%10;
        i /= 10;
    }
    return sum;
}
int len(int i)
{
    int s = 0;
    while(i)
    {
        i/=10;
        s++;
    }
    return s;
}
string s;
int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	int T;cin>>T;
    while(T--)
    {
        cin>>s;
    }
	return 0;
}