/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;


const int maxn = 50 + 10;
char a[maxn][maxn];
char b[maxn*2][maxn*2];

int n;

class pp {
public:
    int x,y;
    
    pp(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

std::vector<class pp> ooo;

bool in(int x, int y) {
    return (x >= 1 && x <= n) && (y >= 1 && y <= n);
}



int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n;
    bool ttt = false;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        cin >> (a[i]+1);
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(a[i][j] == 'o') {
                ooo.push_back(pp(i,j));
            }else {
                cnt++;
            }
    
    for(int i = 0;i < maxn *2 ;i++)
        for(int j = 0;j < maxn*2;j++)
            b[i][j] = '.';
    b[maxn][maxn] = 'o';

    for(int dx = -50; dx <= 50; dx ++) {
        for(int dy = -50; dy <= 50; dy ++) {
            
            if(dx == 0 && dy == 0) continue;
            
            bool flag = true;
            for(auto t : ooo) {
                
                if(in(t.x + dx, t.y + dy)) {
                    if(a[t.x+dx][t.y+dy] == '.') {
                        flag = false;
                    }
                } 
            }
            
            if(flag) {
                ttt = false;
                b[maxn+dx][maxn+dy] = 'x';
            }
        }
    }
    
    
    
    //判NO
    //要重新扫一遍，看是否符合
    
    if(ttt) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl;
    }
    
    for(int dx = -n+1; dx <= n-1;dx ++) {
        for(int dy = -n+1; dy <= n-1;dy++) {
            cout << b[maxn+dx][maxn+dy];
        }
        cout << endl;
    }
    
    return 0;
}