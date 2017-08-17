/*
 *题号：
 *时间：
 *解题思想：数位DP
 *
    
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
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



long long  f(long long x)
{
    long long _ = 0;
    while(x)
    {
        _ += x % 10;
        x /= 10;
    }
    return _;
}


int main(/*int argc, char *argv[]*/) {
	//ios::sync_with_stdio(false);
	long long n,s,ans = 0;
    cin>>n>>s;
    long long i;
    for(i = s;i <= n;i++)
    {
        if( i >= s + f(i))
        {
            if(i % 10 == 9)
            {
                break;
            }
            ans++;
        }
    }
    //cout<<f(10)<<endl;
    
    if(n >= s)
        cout<<ans + n - i + 1 <<endl;
    else 
        cout<<0<<endl;

	return 0;
}





/*
    数位DP模板
int a[20];
int dp[20][state];//不同题目状态不同

int dfs(int pos,//要枚举的位，最低为0
        //state变量,
        bool lead,//前导零,但是不是每个题都要判断前导零
        bool limit//数位上界变量
        )  
{  
    if(pos == -1) return 1;
    //递归边界，既然是按位枚举，最低位是0，那么pos==-1说明这个数我枚举完了  
    //这里一般返回1，表示你枚举的这个数是合法的
    //这就需要你在枚举时必须每一位都要满足题目条件，也就是说当前枚举到pos位，一定要保证前面已经枚举的数位是合法的
    
    //过具体题目不同或者写法不同的话不一定要返回1 
    
    //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)  
    if(!limit && !lead && dp[pos][state] != -1) return dp[pos][state];  
    //常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应
    
    int up = limit ? a[pos] : 9;
    //根据limit判断枚举的上界up;这个的例子前面用213讲过了  
    
    int ans=0;//开始计数
    for(int i = 0;i <= up;i++)
    {  
        //枚举，然后把不同情况的个数加到ans就可以了
        if() ...  
        else if()...
        ans += dfs(pos-1,
                   //状态转移
                   lead && i == 0,
                   limit && i==a[pos])
        
        //当前数位枚举的数是i，再根据题目的约束条件分类讨论 
        //计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目 
        //要求数位上不能有62连续出现,那么就是state就是要保存前一位pre,然后分类 
        //前一位如果是6那么这意味就不能是2 这里一定要保存枚举的这个数是合法
    }
    //计算完，记录状态
    if(!limit && !lead) dp[pos][state]=ans;
    //这里对应上面的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了
    return ans;  
}  
ll solve(ll x)  
{  
    int pos = 0;
    while(x)//把数位都分解出来  
    {  
        a[pos++] = x % 10;//编号为[0,pos)  
        x /= 10;  
    }
    return dfs(pos-1,//从最高位开始枚举
               //一系列状态 ,
                true,
                true
                );
    //刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为
}
int main()  
{  
    ll le,ri;  
    while(~scanf("%lld%lld",&le,&ri))  
    {  
        //初始化dp数组为-1
        printf("%lld\n",solve(ri)-solve(le-1));  
    }  
}
*/