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

#define F(i,a,b) for(int i = a; i < b; i++)


const double eps = 1e-8;
const double pi =  acos(1.0*(-1));
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

typedef long long ll;
typedef std::pair<int,int> P;

using namespace std;

int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
	
    //[=](int a,int b)
    //{
    //    return a>b;
    //}
    int a[] = {1,2,3,4,5};
     
    sort(a,a+5,[](int a,int b){return a>b;});
    for(auto i : a)
    {
        cout<<i<<' '<<endl;
    }
    
    
    try{
        int a = 0;
        if(a == 1) throw false;
        else throw true;
    }
    catch(bool b)
    {
        cout<<123;
    }
    iota();
    /*
    for(){
        for(){
            for(){
                goto:l;
            }
        }
    }
    
    
    l:
        *///...
	return 0;
}