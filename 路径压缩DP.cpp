#include <algorithm>
#include <iostream>
using namespace std;

int f[2000],v[20000],stone[211],b[211];
int main () {
    long long l;
    int s,t,m;
    cin >> l;
    cin >> s >> t >> m;
    memset(f, 0x3f, sizeof(f));
    memset(v, 0, sizeof(v));
    stone[0] = 0;
    for(int i = 1; i <= m; i++) cin >> stone[i];
    stone[m+1] = l;
    sort(stone, stone + m + 2);
    b[0] = 0;
    int cnt = 0;
    
    for(int i = 1;i <= m + 1; i++)
    {
        if(stone[i] - stone[i-1] >= t)
            cnt += (stone[i] - stone[i-1]) % t + t;//路径压缩
        else cnt += stone[i]-stone[i-1];
        v[cnt] = 1;
    }
    v[cnt] = 0;
    v[0] = 0;
    f[0] = 0;
    
    for(int i = 1;i <=cnt+t-1;i++)
    {
        for(int j = s;j <= t;j++)
        {
            if (i >= j) {
                f[i] = min(f[i], f[i-j] + v[i]);
            }
        }
    }
    int ans = INT32_MAX;
    for(int i = cnt; i <= cnt + t-1;i++)
    {
        ans = min(f[i],ans);
    }
    cout<<ans<<endl;
    
    return 0;
}