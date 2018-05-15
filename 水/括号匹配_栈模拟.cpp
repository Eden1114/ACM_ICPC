#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int maxn = 5 * 1e6 + 5;
char s[maxn];
bool it[maxn];
char st_c[maxn];
int  st_i[maxn];
int cnt;

int len;

bool match(char x, char y) {
    if(x == '(' && y == ')') return true;
    if(x == '[' && y == ']') return true;
    if(x == '{' && y == '}') return true;
    return false;
}

bool isLeft(char x) {
    if(x == '(' || x == '[' || x == '{') return true;
    return false;
}

int main(/*int argc, char *argv[]*/) {
    //ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);  
    //freopen("out.txt","w",stdout);
    cin >> (s+1);
    len = strlen(s+1);
    
    int ans = -1;
    int l = -2;
    int r = -2;
    int last_l = -2;
    int last_r = -2;
    cnt = 0;
    for(int i = 1; i <= len;i++)
    {
        if(isLeft(s[i])) {
            st_c[cnt] = s[i];
            st_i[cnt] = i;
            cnt++;
        }
        
        else {
            if(cnt != 0 && match(st_c[cnt-1], s[i])) {
                it[i] = true;
                it[st_i[cnt-1]] = true;
                cnt--;
            }
            
            else {
                cnt = 0;
                last_r = last_l = -2;
            }
        }
    }
    
//    for(int i = 0;i < len;i++)
//    {
//        cout <<it[i];
//    }
    int ss;
    for(int i = 1;i <= len;i++)
    {
        if(it[i] == 1 && it[i-1] == 0) ss = i;
        if(it[i] == 1 && i - ss > ans) {
            r = i;
            l = ss;
            ans = r - l;
        }
    }
    //cout<<l <<' '<< r<<endl;
    for(int i = l; i <= r;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
    return 0;
}