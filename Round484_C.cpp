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
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <cstring>
#include <climits>
#include <limits>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

const double eps=1e-8,pi=acos(1.0*(-1));
const int INF=0x3f3f3f3f,mod=1e9+7;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef std::pair<int,int> P;
typedef long long LL;
typedef long long ll;
using namespace std;

int n;
long long p,q,b;


const int primes_maxn = 1e6;
int primes[primes_maxn];
int primes_vis[primes_maxn];
int findPrime()
{
    int cnt = 0;
    memset(primes_vis,0,sizeof(primes_vis));
    for(int i = 2; i < primes_maxn; i++)
    {
        if(!primes_vis[i])
        {
            primes[cnt++] = i;
            for(int j = i+i; j < primes_maxn; j += i)
            {
                primes_vis[j] = 1;
            }
        }
    }
    primes_vis[1] = 1;
    return cnt;
}



long long PowerMod(long long a, long long b, long long c)
{
    long long ans = 1;
    a = a % c;
    while(b > 0) {
        if(b % 2 == 1)
        ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}

long long gcd(long long a, long long b)
{
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
} 

//判断b是否包含分母所有的因数
bool query(long long p,long long q, long long b) {
        q = q / gcd(p, q);
        
        long long temp;
        while(gcd(q,b) != 1)
        {
            temp =gcd(q, b);
            while(q % temp == 0)
                q /= temp;
            b = temp;
        } 

        if(q == 1) return true;
        else return false;
}

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    //findPrime();
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> p >> q >> b;
        if(query(p,q,b)) cout << "Finite" << endl;
        else cout << "Infinite" << endl;
    }
    
    return 0;
}