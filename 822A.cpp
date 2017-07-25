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
int factorial(int x){
    int fact = 1;
    for(int i = 1;i <= x;i++)
    {
        fact *= i;
    }
    return fact;
}

int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    int minab = min(a,b);
    
    cout<<factorial(minab)<<endl;
    return 0;
}