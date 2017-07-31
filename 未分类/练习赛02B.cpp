#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    char a[1005];
    char b[1005];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s%s",a,b);
        sort(a,a+n);
        sort(b,b+n);
        int x=0;
        int y=0;
        for(int i=0,j=0;j<n;j++)
        {
            if(b[j]>=a[i]) i++;
            else x++;
        }
        for(int i=n-1,j=n-1;i>=0;i--)
        {
            if(b[j]>a[i])
            {
                j--;
                y++;
            }
        }
        printf("%d\n%d\n",x,y);
    }
    return 0;
}