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
    string a = "AOYEUIaoyeui";
    char c;
    while((c = getchar())!=EOF && c != '\n')
    {
        int flag = 0;
        for(int i = 0;i<12;i++)
        {
            if(a[i] == c)
            flag = 1;
        }
        if(flag) ;
        
        else 
        {
           if(c >= 'A'&& c<='Z') c = c + ('a'-'A');
            putchar('.');
            putchar(c);
        }
    }
    putchar('\n');
    return 0;
}