/*
 *题号：None
 *时间：2017年07月28日
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

void function0(){cout<<"我是函数1"<<endl;}
void function1(){cout<<"我是函数2"<<endl;}
void function2(){cout<<"我是函数3"<<endl;}
int cmp(int a, int b)
{
    if (a<b) return 1;
    else return 0;
}

int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	
    //语法糖1：lambda表达式
    int a[] = {1,2,4,3,5};
    sort(a,a+5,cmp);
    
    for(auto i:a)
    {
        cout<<i;
    }
    
    sort(a,a+5,[](int a,int b){return a>b;});
    
    for(auto i:a)
    {
        cout<<i;
    }
    
    for(int i = 0;i < 5;i++)
    {
        cout<<a[i];
    }
    
    /*
        匿名函数形如
        [](){}
        [=](){}传值
        [&](){}传引用
        提高了代码的可读性，不需要再回到开头写cmp(){}
    */
    
    
    //语法糖2：for循环的改进版
    int b[] = {1,2,3,4,5};
    for(int i : b)
    {
        cout<<i<<' '<<endl;
    }
    /*
        这里的for循环可以直接按照迭代变量递增的方式
        遍历整个数组
    */
    
    //语法糖3：auto类型
    char c[] = "123123";
    double d[] = {1.111,2.22,3.333};
    for(auto i : c)
    {
        cout<<i<<' '<<endl;
    }
    for(auto i : d)
    {
        cout<<i<<' '<<endl;
    }
    /*
        auto关键词会根据后面的类型自动识别类型
    */
    
    
    //语法3：异常处理（待完善）
    try
    {
        int a = 0;
        if(a == 1) throw true;
        else throw false;
    }
    catch(bool b)
    {
        cout<<123<<endl;
    }
    /*
        使用异常的时候务必谨慎
        抛出异常，本质是把锅背在用户身上
        比如输入不合法等
        对于代码中的语法问题，不建议抛异常
        而应该直接暴露出来，有bug的地方就
        暴露出来，便于修改
    */
    
    //语法4：goto的用法
    while(1)
    {
        while(1)
        {
            while (1)
            {
                if(1)
                {
                    goto label1;
                }
            }
        }
    }
label1:
    int balabala = 123;
    //char buffer[10];
    //memset(buffer,0,sizeof buffer);
    printf("%d\n",balabala);        
    //iota(balabala,buffer,2);
    //printf("%s\n",buffer);
    
    
    /*
        goto本身有害
        底层实际是汇编指令中的jmp
        能不用就不用
        典型的用法是跳出多重循环
        这里用的话，比用标志变量的
        写法，可读性更好
    */
    
    //语法5：函数指针数组
    //先看函数指针：两种写法都是合法的
    void (*f)() = function0;
    void (*g)() = &function0;
    (*f)();
    (*g)();
    
    //这里是函数指针数组的定义
    void (*funcs[3])() = {function0,function1,function2};
    
    funcs[2] = function0;
    funcs[1] = function2;
    funcs[0] = function1;
    
    //用for循环调用
    
    for(int i = 0;i < 3;i++)
    {
        (*funcs[i])();
    }
    //函数指针数组的最大用途就是写菜单系统
    //刚开始if-else switch写起来会很简单
    //但是不便于以后的修改
    //对于大型的命令行处理，用函数指针数组更加的方便
    
                
    
    return 0;
}