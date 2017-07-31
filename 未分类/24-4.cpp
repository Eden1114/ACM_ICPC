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
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n;
    int a[1e5 + 10];
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 1; i <= n;i++)
        {
            cin>>a[i];
        }
        if(n == 1)
        {
            cout<<a[1]<<endl;
        }
        else if(n % 2 == 0)
        {
            int maxr = a[n] + a[1];
            for(int i = 1;i <= n - 1;i++)
            {
                maxr = max(maxr,a[i] + a[i+1]);
            }
            cout<<maxr<<endl;
        }
    
        else 
        {
            
        }
    }
    
    return 0;
}




int judge(int num) {  
    int x = arr[1], y = num - arr[1];  
    front[1] = x;  
    back[1] = 0;  
    for (int i = 2; i <= n; i++) {  
        if (i % 2 == 1) {  
            back[i] = min(y - back[i - 1], arr[i]); //尽量往后取  
            front[i] = arr[i] - back[i];   
        }   
        else {  
            front[i] = min(x - front[i - 1], arr[i]); //尽量往前取  
            back[i] = arr[i] - front[i];  
        }
    }  
    return front[n] == 0;   
}  




while (scanf("%d", &n) == 1 && n) 
{  
    for (int i = 1; i <= n; i++)   
    {
        scanf("%d", &arr[i];  
    }
    if (n == 1)
    {  
        printf("%d\n", arr[1]);  
        continue;    
    }   
  
    arr[n + 1] = arr[1];   
    int L = 0, R = 0;  
    for (int i = 1; i <= n; i++)   
        L = max(L, arr[i] + arr[i + 1]);  
  
    memset(front, 0,sizeof(front));  
    memset(back, 0,sizeof(back));  
    if (n % 2 == 1) {  
        for (int i = 1; i <= n; i++)   
            R = max(R, arr[i] * 3); 
        while (L < R) {
            int mid = L + (R - L) / 2;  
            if (judge(mid))   
                R = mid;  
            else  
                L = mid + 1;   
        }   
    }  
        printf("%d\n", L);   
}  
