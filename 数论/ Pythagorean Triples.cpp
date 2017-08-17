/*
Codeforces:707C
题解：http://blog.csdn.net/sinat_34336698/article/details/53008518
思想方法：
勾股数组定理
对于每个本原勾股数组(a,b,c)(其中a是奇数，b是偶数)
则  a = st
    b = (s * s - t * t) / 2
    c = (s * s + t * t) / 2
    其中 s > t >= 1是任意没有公因数的奇数
*/
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