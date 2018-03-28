//A题Stack模拟
#include <iostream>
#include <stack>
using namespace  std;
const int maxn = 1500 + 5;
int a[maxn];
int n;
stack<int> st;

int main() {
    cin >> n;
    cin>>a[1];
    for(int i = 1;i <= a[1];i++)
    {
        st.push(i);
    }
    cout << 1;
    st.pop();
    
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        for(int j = a[i-1] + 1; j <= a[i]; j++)
        {
            st.push(j);
        }
        int top = st.top();
        st.pop();
        cout<< ' ' << a[i] - top + 1;
    }
    cout << endl;
    return 0;
}