# ACM模板  
-----
 
## 1.筛法求素数  

```cpp
const int MAX = 1000010;
int Prime[MAX];
int Mark[MAX];
void prime()
{
    int index = 0;
    memset(Mark,0,sizeof(Mark));
    for(int i = 2; i < MAX; i++)
    {
        if(Mark[i] == 0)
        {
            Prime[index++] = i;
        }
        for(int j = 0; j < index && Prime[j] * i < MAX; j++)
        {
            Mark[i * Prime[j]] = 1;
            if(i % Prime[j] == 0)
                break;
        }
    }
}
```  
其中Mark[x] == 0,x就是素数。 

## 2.常用STL函数
2.1 `sort(begin,end,compare);`  
2.2 `binary_search();`  
2.3 `lower_bound();`  
2.4 `upper_bound();`  
2.5 `next_permutation();`  
2.6 `prev_permutation();`  

## 3.DFS模板
```cpp
void dfs(int x,int y,int sum)
{
    int i,xx,yy;
    if(flag == 1)
        return;
    //已经访问过的结点不再访问，避免死循环
        
    if(x == ex && y == ey && sum == t)
    {
        flag = 1;
        return;
    }
    //和
    
    int mindis = abs(x-ex) + abs(y-ey);  
    /*当前点到终点的最短距离*/
    
    if(mindis>t-sum||(mindis+ t-sum )%2!=0)  
        return;
    for(i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx>=0&&xx<n&&yy>=0&&yy<m&&!vis[xx][yy]&&map[xx][yy]!='X')  
        /*在map范围内且可以继续搜下去*/
        {
            vis[xx][yy]=1;
            dfs(xx,yy,sum+1);
            vis[xx][yy]=0;
        }
    }
}
```
## 4.最大公约数（欧几里得算法）
```cpp 
int gcd(int a, int b)
{ 
    return a == 0 ? b : gcd(b % a, a);
} 
```

## 5.错排公式
问题： n本不同的书放在书架上。现重新摆放，使每本书都不在原来放的位置。有几种摆法？

递归公式：  
**D(n) = (n-1) [D(n-2) + D(n-1)]**  
**D(1) = 0, D(2) = 1.**   

通项公式：  
**D(n) = n! [(-1)^2/2! + … + (-1)^(n-1)/(n-1)! + (-1)^n/n!]**  
其他算法：  
**D(n) = [n!/e+0.5]** ，其中e是自然对数的底，[x]为x的整数部分  

## 6.俄罗斯乘法
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

## 7.排列组合

## 8.快速幂
快速幂就是快速计算底数的n次幂。  
Divide and Conquer  


```cpp
//快速幂 ans == a^b mod c

long long PowerMod(long long a
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


## 9.矩阵乘法

## 10. 算法复杂度分析
1秒大约能执行108次简单运算   n = 1000000 ~ O(n)   n = 10000O ~ (nlgn)   n = 1000 ~ O(n2), O(n2lgn)   n = 100 ~ O(n3)   n = 10 ~ O(an), O(n!)  
 
## 11.尺取法  

## 12.STL模板类
###pair  
  pair 是 一种模版类型。每个pair 可以存储两个值。这两种值无限制。也可以将自己写的struct的对象放进去。  
    `pair<string,int> p1;`   
    `pair<int,int> p2;`  
    `pair<double,int> p3;`  
###vector
```cpp
#include<vector>
vector<int> vec;
vec.begin();//返回第一个元素
vec.end();//返回第二个元素
vec.push_back();//在最后添加元素
vec.insert();

```
###string
###set
```
#include <set>
set<int> se;
se.begin();//返回set容器的第一个元素

se.end();//返回set容器的最后一个元素

se.clear();//删除set容器中的所有的元素

se.empty();//判断set容器是否为空

se.max_size();//返回set容器可能包含的元素最大个数

se.size();//返回当前set容器中的元素个数

se.rbegin();//reverse_begin,返回的值和end()相同

se.rend();//reverse_end,返回的值和rbegin()相同

se.count();//查找set中某键值出现的次数(1或0)
```
###map
```
#include <map>

```
###stack
```cpp
#include <stack>

```
###queue


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
## 13.计算几何
三 重心法

上面这个方法简单易懂，速度也快，下面这个方法速度更快，只是稍微多了一点数学而已

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
## 14.其他
1. 关于取模，有时关于一个固定的值取模，可以通过位运算实现。
2. 读入按照字符串比较（数字比较） 
 
