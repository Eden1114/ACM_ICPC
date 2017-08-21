# ACM模板  
----------------

# 0.算法复杂度分析
----------------
现代的计算机，1秒大约能执行10^8次简单运算  *  n = 10^20 ~ O(lgn)  
*  n = 10^12 ~ O(n^(1/2))  
*  n = 10^6  ~ O(n)  *  n = 10^5  ~ O(nlgn)   *  n = 10^3  ~ O(n2), O(n2lgn)  *  n = 10^2  ~ O(n3)  *  n = 10    ~ O(A(a,b)), O(n!)  

用自己实现的算法的复杂度，与最大的数据量和题意比较就可以知道会不会TLE了。

# 1.数学类
-----------------
## 1.1.数论
### 1.1.1.筛法求素数  

```cpp
const int primes_maxn = 1e5+10;
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
    return cnt;
}
```  
其中primes_vis[x] == 0,x就是素数。  
primes[] 保存了1 ~ primes_maxn的素数。
### 1.1.2.最大公约数和最小公倍数（欧几里得算法）
```cpp 
//最大公约数
long long gcd(long long a, long long b)
{
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
} 
//相当于利用了恒等式:gcd(a,b) == gcd(b,a mod b)

//最小公倍数
long long lcm(long long a,long long b)
{
	if (a < b) swap(a, b);
	return a / gcd(a, b) * b;
}

```

### 1.1.3.拓展欧几里得算法
拓展欧几里得算法在求出最大公约数的同时，也完成了对方程：ax + by = gcd(a,b)的平凡整数解的求解。具体原理可以参照wikipedia。  

***a,b,为正整数;x,y是整数;则形如ax+by的最小正整数是gcd(a,b)***  

```
int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if(b)
    {
    	d = extgcd(b, a%b, y, x);
    	y -= (a / b) * x;
    }
    else
    {
    	x = 1;
    	y = 0;
    }
    return d;
}
//在这里a,b要满足a > b.
```
### 1.1.4.求约数
```
const int divisor_maxn = 1e3 + 10;
int divisor[divisor_maxn];
int findDivisor(int n)
{
	int cnt = 0;
	for(i = 1;i * i < n;i++)
	{ 
	    if (n % 1 == 0)
	    {
	    	res[cnt++] = i;
	    	if(i*i != n)
	    		res[cnt++] = n / i;
	    }
	}
}
```
这里也可以用priority_queue来存约数，使得其有序。

### 1.1.5.勾股三元组(PPT)
参照数论概论的第一节推结论就好。

### 1.1.6.逆元

### 1.1.7中国剩余定理


###拓展内容
莫比乌斯反演  
大数因数分解  
Pollard rho 算法  
二次剩余  
Pell方程  
原根  

## 1.2.组合数学
### 1.2.1.阶乘
在计算排列组合的时候，阶乘是常常需要用到的值，因为阶乘增长的速度特别快，通常会对一个大质数取模（比如1e9+7）。在计算阶乘的时候，通常会进行预处理，以减小算法复杂度。

```
const int factor_maxn = 1e5 + 10;
long long factor[factor_maxn];
void findFactor(int mod = 1e9+7)
{
    factor[0] = 1;
    for(int i = 1;i < factor_maxn;i++)
    {
        factor[i] = i * factor[i-1] % mod;
    }
}
```


### 1.2.2.组合数
对组合数的求解一般有四种。  
1.暴力求解  
**C(m,n) = n!/(m!*(n-m)!)**  

2.递推公式  
**C(m,n) = C(m,n-1)+C(m-1,n-1)**  
一般用于n,m < 1000的情况

3.预处理阶乘和阶乘的逆元  


4.Lucas定理
```
ll lucas(ll n,ll m,int p)
{
    if(n<m)return 0;//非法组合数，方案数为0
    if(n<p &&m<p)//可以直接计算，直接算逆元
        return factor[n]*quickPow(factor[m]*factor[n-m]%p,p-2,p)%p;
    else//不能算就用Lucas定理迭代
        return lucas(n/p,m/p,p)*lucas(n%p,m%p,p)%p;
}
```

### 1.2.3.错排公式
问题： n本不同的书放在书架上。现重新摆放，使每本书都不在原来放的位置。有几种摆法？

递归公式：  
**D(n) = (n-1) [D(n-2) + D(n-1)]**  
**D(1) = 0, D(2) = 1.**   

通项公式：  
**D(n) = n! [(-1)^2/2! + … + (-1)^(n-1)/(n-1)! + (-1)^n/n!]**  
其他算法：  
**D(n) = [n!/e+0.5]** ，其中e是自然对数的底，[x]为x的整数部分  
## 1.3.矩阵
### 1.3.1.矩阵的实现
```
const int matrixm;
const int matrixn;
Template<class T>
struct Matrix
{
    T  m[matrixm][matrixn];  
};
  

```
### 1.3.2 矩阵运算
矩阵的乘法

```
Matrix Mul(Matrix a,Matrix b)  
{  
    int i, j, k;  
    Matrix c;  
    for(i = 1; i <= ssize; i++)  
    {  
        for(j = 1; j <= ssize; j++)  
        {  
            c.m[i][j]=0;  
            for(k = 1; k <= ssize; k++)  
            {  
                c.m[i][j]+=(a.m[i][k]*b.m[k][j]);  
                c.m[i][j]%=mod;  
            }  
        }  
    }  
    return c;  
}
```

###1.3.3矩阵快速幂

  
Matrix quickpagow(LL n)  
{  
    Matrix m = A, b = I;  
    while(n)  
    {  
        if(n & 1)  
            b = Mul(b,m);  
        n = n >> 1;
        m = Mul(m,m);
    }
    return b;  
}  

## 1.4.大数和高精度
### 1.4.1.大数
```cpp
#include<iostream>   
#include<string>   
#include<iomanip>   
#include<algorithm>   
using namespace std;   
  
#define MAXN 9999  
#define MAXSIZE 10  
#define DLEN 4  
  
class BigNum  
{   
public:    
    int a[500];    //可以控制大数的位数   
    int len;       //大数长度  
public:   
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //构造函数  
    BigNum(const int);       //将一个int类型的变量转化为大数  
    BigNum(const char*);     //将一个字符串类型的变量转化为大数  
    BigNum(const BigNum &);  //拷贝构造函数  
    BigNum &operator=(const BigNum &);   //重载赋值运算符，大数之间进行赋值运算  
      
    friend istream& operator>>(istream&,  BigNum&);   //重载输入运算符  
    friend ostream& operator<<(ostream&,  BigNum&);   //重载输出运算符  
      
    BigNum operator+(const BigNum &) const;   //重载加法运算符，两个大数之间的相加运算   
    BigNum operator-(const BigNum &) const;   //重载减法运算符，两个大数之间的相减运算   
    BigNum operator*(const BigNum &) const;   //重载乘法运算符，两个大数之间的相乘运算   
    BigNum operator/(const int   &) const;    //重载除法运算符，大数对一个整数进行相除运算  
      
    BigNum operator^(const int  &) const;    //大数的n次方运算  
    int    operator%(const int  &) const;    //大数对一个int类型的变量进行取模运算      
    bool   operator>(const BigNum & T)const;   //大数和另一个大数的大小比较  
    bool   operator>(const int & t)const;      //大数和一个int类型的变量的大小比较  
      
    void print();       //输出大数  
};   
BigNum::BigNum(const int b)     //将一个int类型的变量转化为大数  
{   
    int c,d = b;  
    len = 0;  
    memset(a,0,sizeof(a));  
    while(d > MAXN)  
    {  
        c = d - (d / (MAXN + 1)) * (MAXN + 1);   
        d = d / (MAXN + 1);  
        a[len++] = c;  
    }  
    a[len++] = d;  
}  
BigNum::BigNum(const char*s)     //将一个字符串类型的变量转化为大数  
{  
    int t,k,index,l,i;  
    memset(a,0,sizeof(a));  
    l=strlen(s);     
    len=l/DLEN;  
    if(l%DLEN)  
        len++;  
    index=0;  
    for(i=l-1;i>=0;i-=DLEN)  
    {  
        t=0;  
        k=i-DLEN+1;  
        if(k<0)  
            k=0;  
        for(int j=k;j<=i;j++)  
            t=t*10+s[j]-'0';  
        a[index++]=t;  
    }  
}  
BigNum::BigNum(const BigNum & T) : len(T.len)  //拷贝构造函数  
{   
    int i;   
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)  
        a[i] = T.a[i];   
}   
BigNum & BigNum::operator=(const BigNum & n)   //重载赋值运算符，大数之间进行赋值运算  
{  
    int i;  
    len = n.len;  
    memset(a,0,sizeof(a));   
    for(i = 0 ; i < len ; i++)   
        a[i] = n.a[i];   
    return *this;   
}  
istream& operator>>(istream & in,  BigNum & b)   //重载输入运算符  
{  
    char ch[MAXSIZE*4];  
    int i = -1;  
    in>>ch;  
    int l=strlen(ch);  
    int count=0,sum=0;  
    for(i=l-1;i>=0;)  
    {  
        sum = 0;  
        int t=1;  
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)  
        {  
            sum+=(ch[i]-'0')*t;  
        }  
        b.a[count]=sum;  
        count++;  
    }  
    b.len =count++;  
    return in;  
      
}  
ostream& operator<<(ostream& out,  BigNum& b)   //重载输出运算符  
{  
    int i;    
    cout << b.a[b.len - 1];   
    for(i = b.len - 2 ; i >= 0 ; i--)  
    {   
        cout.width(DLEN);   
        cout.fill('0');   
        cout << b.a[i];   
    }   
    return out;  
}  
  
BigNum BigNum::operator+(const BigNum & T) const   //两个大数之间的相加运算  
{  
    BigNum t(*this);  
    int i,big;      //位数     
    big = T.len > len ? T.len : len;   
    for(i = 0 ; i < big ; i++)   
    {   
        t.a[i] +=T.a[i];   
        if(t.a[i] > MAXN)   
        {   
            t.a[i + 1]++;   
            t.a[i] -=MAXN+1;   
        }   
    }   
    if(t.a[big] != 0)  
        t.len = big + 1;   
    else  
        t.len = big;     
    return t;  
}  
BigNum BigNum::operator-(const BigNum & T) const   //两个大数之间的相减运算   
{    
    int i,j,big;  
    bool flag;  
    BigNum t1,t2;  
    if(*this>T)  
    {  
        t1=*this;  
        t2=T;  
        flag=0;  
    }  
    else  
    {  
        t1=T;  
        t2=*this;  
        flag=1;  
    }  
    big=t1.len;  
    for(i = 0 ; i < big ; i++)  
    {  
        if(t1.a[i] < t2.a[i])  
        {   
            j = i + 1;   
            while(t1.a[j] == 0)  
                j++;   
            t1.a[j--]--;   
            while(j > i)  
                t1.a[j--] += MAXN;  
            t1.a[i] += MAXN + 1 - t2.a[i];   
        }   
        else  
            t1.a[i] -= t2.a[i];  
    }  
    t1.len = big;  
    while(t1.a[len - 1] == 0 && t1.len > 1)  
    {  
        t1.len--;   
        big--;  
    }  
    if(flag)  
        t1.a[big-1]=0-t1.a[big-1];  
    return t1;   
}   
  
BigNum BigNum::operator*(const BigNum & T) const   //两个大数之间的相乘运算   
{   
    BigNum ret;   
    int i,j,up;   
    int temp,temp1;     
    for(i = 0 ; i < len ; i++)  
    {   
        up = 0;   
        for(j = 0 ; j < T.len ; j++)  
        {   
            temp = a[i] * T.a[j] + ret.a[i + j] + up;   
            if(temp > MAXN)  
            {   
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);   
                up = temp / (MAXN + 1);   
                ret.a[i + j] = temp1;   
            }   
            else  
            {   
                up = 0;   
                ret.a[i + j] = temp;   
            }   
        }   
        if(up != 0)   
            ret.a[i + j] = up;   
    }   
    ret.len = i + j;   
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)  
        ret.len--;   
    return ret;   
}   
BigNum BigNum::operator/(const int & b) const   //大数对一个整数进行相除运算  
{   
    BigNum ret;   
    int i,down = 0;     
    for(i = len - 1 ; i >= 0 ; i--)  
    {   
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;   
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;   
    }   
    ret.len = len;   
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)  
        ret.len--;   
    return ret;   
}  
int BigNum::operator %(const int & b) const    //大数对一个int类型的变量进行取模运算      
{  
    int i,d=0;  
    for (i = len-1; i>=0; i--)  
    {  
        d = ((d * (MAXN+1))% b + a[i])% b;    
    }  
    return d;  
}  
BigNum BigNum::operator^(const int & n) const    //大数的n次方运算  
{  
    BigNum t,ret(1);  
    int i;  
    if(n<0)  
        exit(-1);  
    if(n==0)  
        return 1;  
    if(n==1)  
        return *this;  
    int m=n;  
    while(m>1)  
    {  
        t=*this;  
        for( i=1;i<<1<=m;i<<=1)  
        {  
            t=t*t;  
        }  
        m-=i;  
        ret=ret*t;  
        if(m==1)  
            ret=ret*(*this);  
    }  
    return ret;  
}  
bool BigNum::operator>(const BigNum & T) const   //大数和另一个大数的大小比较  
{   
    int ln;   
    if(len > T.len)  
        return true;   
    else if(len == T.len)  
    {   
        ln = len - 1;   
        while(a[ln] == T.a[ln] && ln >= 0)  
            ln--;   
        if(ln >= 0 && a[ln] > T.a[ln])  
            return true;   
        else  
            return false;   
    }   
    else  
        return false;   
}  
bool BigNum::operator >(const int & t) const    //大数和一个int类型的变量的大小比较  
{  
    BigNum b(t);  
    return *this>b;  
}  
  
void BigNum::print()    //输出大数  
{   
    int i;     
    cout << a[len - 1];   
    for(i = len - 2 ; i >= 0 ; i--)  
    {   
        cout.width(DLEN);   
        cout.fill('0');   
        cout << a[i];   
    }   
    cout << endl;  
}  
int main(void)  
{  
    int i,n;  
    BigNum x[101];      //定义大数的对象数组  
    x[0]=1;  
    for(i=1;i<101;i++)  
        x[i]=x[i-1]*(4*i-2)/(i+1);  
    cin>>n;  
    x[n].print();  
    x[n+1].print();  
    (x[n]+x[n+1]).print();  
    (x[n]-x[n+1]).print();  
    (x[n]*x[n+1]).print();  
    (x[n]/100).print();  
    (x[n]^20).print();  
    cout<<x[n]%100<<endl;  
    return 0;  
}  
```
## 1.4.计算几何
###1.4.1判断点在三角形内
三角形的三个点在同一个平面上，如果选中其中一个点，其他两个点不过是相对该点的位移而已，比如选择点A作为起点，那么点B相当于在AB方向移动一段距离得到，而点C相当于在AC方向移动一段距离得到。

所以对于平面内任意一点，都可以由如下方程来表示

P = A +  u * (C – A) + v * (B - A) // 方程1

如果系数u或v为负值，那么相当于朝相反的方向移动，即BA或CA方向。那么如果想让P位于三角形ABC内部，u和v必须满足什么条件呢？有如下三个条件

u >= 0

v >= 0

u + v <= 1

几个边界情况，当u = 0且v = 0时，就是点A，当u = 0,v = 1时，就是点B，而当u = 1, v = 0时，就是点C

整理方程1得到P – A = u(C - A) + v(B - A)

令v0 = C – A, v1 = B – A, v2 = P – A，则v2 = u * v0 + v * v1，现在是一个方程，两个未知数，无法解出u和v，将等式两边分别点乘v0和v1的到两个等式

(v2) • v0 = (u * v0 + v * v1) • v0

(v2) • v1 = (u * v0 + v * v1) • v1

注意到这里u和v是数，而v0，v1和v2是向量，所以可以将点积展开得到下面的式子。

v2 • v0 = u * (v0 • v0) + v * (v1 • v0)  // 式1

v2 • v1 = u * (v0 • v1) + v * (v1• v1)   // 式2

解这个方程得到

u = ((v1•v1)(v2•v0)-(v1•v0)(v2•v1)) / ((v0•v0)(v1•v1) - (v0•v1)(v1•v0))

v = ((v0•v0)(v2•v1)-(v0•v1)(v2•v0)) / ((v0•v0)(v1•v1) - (v0•v1)(v1•v0))

是时候上代码了，这段代码同样用到上面的Vector3类

```
// Determine whether point P in triangle ABC
bool PointinTriangle(Vector3 A, Vector3 B, Vector3 C, Vector3 P)
{
    Vector3 v0 = C - A ;
    Vector3 v1 = B - A ;
    Vector3 v2 = P - A ;

    float dot00 = v0.Dot(v0) ;
    float dot01 = v0.Dot(v1) ;
    float dot02 = v0.Dot(v2) ;
    float dot11 = v1.Dot(v1) ;
    float dot12 = v1.Dot(v2) ;

    float inverDeno = 1 / (dot00 * dot11 - dot01 * dot01) ;

    float u = (dot11 * dot02 - dot01 * dot12) * inverDeno ;
    if (u < 0 || u > 1) // if u out of range, return directly
    {
        return false ;
    }
    float v = (dot00 * dot12 - dot01 * dot02) * inverDeno ;
    if (v < 0 || v > 1) 
    // if v out of range, return directly
    {
        return false ;
    }
    return u + v <= 1 ;
}
```
##其他
### 8.快速幂
快速幂就是快速计算底数的n次幂。  
Divide and Conquer  


```cpp
//快速幂 ans == a^b mod c

long long quickPow(long long a
, long long b
/*, long long c*/)
{
	long long ans = 1;
	//a = a % c;
	while(b > 0)
	{
		if(b & 1)
		{
			ans *= a;
			//ans %= c;
		}
		b /= 2;
		a *= a;
		//a %= c;
	}
	return ans;
	/*
		去掉注释可以用来取模
	*/
}
```

### 5.俄罗斯乘法
两个很大的数直接相乘结果会爆long long,有时使用俄罗斯乘法可以避免。  
俄罗斯乘法是一种计算两数相乘的算法。 
举例如下：   
计算 35*72  
过程  
35 72  
17 144  
8 288  
4 576  
2 1152  
1 2304  
从上到下，对每一行，若左边的数字若为奇数，则将右边的数字取出，累加。  
72 + 144 + 2304 == 2520  
累加的结果2520即为乘积。  

```cpp
long long (long long m,long long n)
{  
    long long ans = 0;  
    while(m){
        if(m & 1)//m是奇数
        {
            ans += n; 
            //ans %= p;
        }
        m /= 2;
        n *= 2;
        //n %= p;
    }
    /*
    当结果很大的时候
    如果要返回对p取模的值
    可以把注释去了
    */
    return ans;
}
```

# 2.函数库和STL容器
## 1.常用函数
2.1 `sort(begin,end,compare);`  
2.2 `binary_search();`  
2.3 `lower_bound();`  
2.4 `upper_bound();`  
2.5 `next_permutation();`  
2.6 `prev_permutation();`  
2.7 `itoa();`

## 12.STL容器
###pair  
  pair 是 一种模版类型。每个pair 可以存储两个值。这两种值无限制。也可以将自己写的struct的对象放进去。  
    
```cpp
	std::pair <string,int> p1;
    std::pair <int,int> p2;
    std::pair <double,int> p3;
    p1.first;
    p1.second;
    //返回第一个元素，返回第二个元素
```
###vector
```cpp
#include<vector>
vector<int> vec;

//iterator
vec.begin();
vec.end();
//vec.begin()返回第一个元素的指针,vec.end()返回最后一个元素的`后继`的指针
//指向最后一个元素的指针是 vec.end()-1

vec.cbegin();
vec.cend();
//c 表示const,返回常量指针

vec.rbegin();
vec.rend();
vec.crbegin();
vec.crend();
//r表示reverse 逆序


vector<int>::iterator t = vec.begin();

while(t != vec.end())
{
	cout<<*t<<endl;
	t++;
}
//使用迭代器遍历

for(int i : vec)
{
	cout<<i<<endl;
}
//for循环的高级写法遍历



vec.push_back();//在最后添加元素
vec.insert();
vec.front();//返回第一个元素
vec.back();//返回最后一个函数
vec.size();//返回元素个数

/*
 * 注意，只能通过&vec[i]获得第i个元素的地址，无法通过vec + i 获得。
 */

```
###string
```
string str;
str.c_str();//返回对应的C type 字符串

```
###set
```
#include <set>
set<int> se;
se.begin();//返回set容器的第一个元素

se.end();//返回set容器的最后一个元素的后继

se.clear();//删除set容器中的所有的元素

se.empty();//判断set容器是否为空

se.max_size();//返回set容器可能包含的元素最大个数

se.size();//返回当前set容器中的元素个数

se.rbegin();//reverse_begin,返回的值和end()相同

se.rend();//reverse_end,返回的值和rbegin()相同

se.count();//查找set中某键值出现的次数(1或0)

se.erase()//删除某个元素

multiset<int> m_se;


bitset <int> b_se;



```
###map
```
#include <map>

```
###multimap
```
#include <map>
multimap<int,int> m_map;
m_map.

```


###stack
```cpp
#include <stack>

```
###queue
```
#include <queue>
queue<int> que;
	que.push();
	que.pop();
	que.size();
	que.empty();
	que.front();//返回最低端元素
```


###priority_queue
```
#include <queue>
	priority_queue<int> p_que;
	p_que.push(1);//添加元素1
	p_que.pop();//弹出第一个元素
	p_que.top();//返回第一个元素
	p_que.size();返回优先队列中的元素个数
	/*
		priority_queue 添加进新的元素后会自动排序
	*/
```

### hash
```
unordered_map
unordeeed_set
```


# 3.模板

## 4.DFS模板
```cpp
dx[]={0,0,1,-1};
dy[]={1,-1,0,0};
void dfs(int x,int y)
{
    if(x < 0 || y < 0 || x >= m || y >= n) return;
    //访问越界，返回
    if(vis[x][y]) return;
    //访问过了，返回
    
    //visit
    {
    	...//一些别的操作
    	vis[x][y] = 1;//表示访问过了
    }
    
    for(int i = -1;i <= 1;i++)
    	for(int j = -1;j <=1;j++)
    		dfs(x+i,y+j);
    //递归调用其他节点（八连通）
    		
    //递归调用（四联通）
    //for(int i = 0;i < 4;i++)
    //{
    //    dfs(x+dx[i],y+dy[i]);
    //}		
}
```

 
## 11.尺取法  


## 15.其他
1. 关于取模，有时关于一个固定的值取模，可以通过位运算实现。
2. 读入按照字符串比较（数字比较） 
3. `ios::sync_with_stdio(false)` 使用后，cin 和 scanf 就不能混用了  
4. 迭代器失效的问题
5. `__builtin_popcount();`用于处理
6. `memset(array,sizeof(array));``memset(array,-1,sizeof(array);`一个用来初始化整个内存区域为0，一个用来初始化整个内存区域为1  
7. 哈哈
 
