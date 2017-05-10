/*
CodeForces - 798D
Hardest Point:
a,b->(a+b)/2,(a-b)/2
(a+b)/2,(a-b)/2->2a,2b
Other:
1.gcd module
2.Finite State Machine
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
long long  gcd(long long  a,long long b)
{
    return b == 0?a:gcd(b,a%b);
}
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    long long data[100100];
    long long n;
    cin>>n;
    for(int i = 0; i < n;i++)
    {
        cin>>data[i];
    }
    int d = data[0];
    for(int i = 1; i < n;i++)
    {
        d = gcd(d,data[i]);
    }
    int ans = 0;
    if(d <= 1)
    {
        int odd = 0;
        for(int i = 0;i < n;i++)
        {
            if(data[i] % 2 != 0) odd++;
            else if(odd != 0)
            {
                if(odd % 2 == 0)
                {
                    ans += odd/2;
                }
                else
                {
                    ans += odd/2 + 2;
                }
                odd = 0;
            }
        }
        if(odd != 0)
        {
            if(odd % 2 == 0)
            {
                ans += odd/2;
            }
            else
            {
                ans += odd/2 + 2;
            }
            odd = 0;
        }
    }
    cout<<"YES\n";
    cout<<ans<<endl;
    return 0;
}