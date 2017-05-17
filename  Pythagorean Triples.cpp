#include <iostream>
using namespace std;
int main()
{
    long long n,a,b,c;
    scanf("%lld",&a);
    
    if(a % 2 == 1)
    {
        n = ( a - 1 ) / 2;
        b = 2 * n * ( n + 1);
        c = 2 * n * (n + 1) + 1;
    }
    else
    {
        n = a / 2;
        b = n * n - 1;
        c = n * n + 1;
    }
    
    if( a * a + b * b == c * c && a && b && c)
        printf("%lld %lld\n",b,c);
    else
        printf("-1\n");
    
    return 0;
}