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
char a[15][15];
bool isOK(int x,int y){
    a[x][y] = 'X';
    
    do{
        int t = 0;
        int i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;j--;}
        i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;j++;}
        if(t >= 6) {a[x][y] = '.';return true;}
    }while(0);

    do{
        int t = 0;
        int i = x,j = y;
        while(a[i][j] == 'X' && i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;i--;}
        i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;i++;}
        if(t >= 6) {a[x][y] = '.';return true;}
    }while(0);

    do{
        int t = 0;
        int i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;i--;j++;}
        i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;i++;j--;}
        if(t >= 6) {a[x][y] = '.';return true;}
    }while(0);


    do{
        int t = 0;
        int i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;i--;j--;}
        i = x,j = y;
        while(a[i][j] == 'X'&& i >= 1 && i <= 10 && j >= 1 &&j <= 10) {t++;i++;j++;}
        if(t >= 6) {a[x][y] = '.';return true;}
        }while(0);
        
    a[x][y] = '.';
    return false;
}


int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    char a[15][15];
    for(int i = 1; i <= 10;i++)
    {    
        for(int j = 1;j <= 10;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(int i = 1; i <= 10;i++)
    {
        for(int j = 1;j <= 10;j++)
        {
            if(a[i][j] == '.')
            {
                if(isOK(i,j))
                {
                    cout<<"YES"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}