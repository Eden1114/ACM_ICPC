#include <iostream>
using namespace std;
const int maxl = 1e4 + 5;
bool tree[maxl];
int l,n,ans;
int main() {
    cin>>l>>n;
    while (n--) {
        int l,r;
        cin >> l >> r;
        for(int i = l;i <= r;i++)
        {
            tree[i] = true;
        }
    }
    for(int i = 0;i <= l;i++)
    {
        if(tree[i] == false) ans++;
    }
    cout<<ans<<endl;
    return 0;
}