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
using namespace std;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
#define F(n) for(int i = 0; i < n; i++)
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int n,k,res;
    scanf("%d%d",&n,&k);
    if(n <= k){res = 2;} //鱼比锅少
    else{res = 2*n/k + (2*n%k ?1:0);}
    printf("%d\n",res);
    return 0;
}