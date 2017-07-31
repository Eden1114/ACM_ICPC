#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
const double eps = 1e-8;
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int m,n,k;
    cin>>n>>m>>k;//n行m列
    int t = k;
    int r=1,c=1;
    while(t)
    {
        if(t != 1)
        {
            printf("2");
            
            printf(" %d %d",r,c);
            if(r % 2)
            {
                if(c - 1 >= 1) c--;
                else r++;
            }
            else
            {
                if(c + 1 <= m) c++;
                else r++;
            }
            printf(" %d %d",r,c);
            
            if(r % 2)
            {
                if(c - 1 >= 1) c--;
                else r++;
            }
            else
            {
                if(c + 1 <= m) c++;
                else r++;
            }
            
            t--;
        }
        
        else if(t == 1)
        {
            printf("%d",m*n-2*k+2);
            while(1)
            {
                if(r%2) {
                    if(r == n && c == 1) 
                    
                    break;
                }
                else {
                    if(r == n && c == m) break;
                }
                
                printf(" %d %d",r,c);
                if(r%2)
                {
                    if(c - 1 >= 1) c--;
                    else r++;
                }
                else {
                    if(c + 1 <= m) c++;
                    else r++;
                }
            }
            t--;
        }
       
    }
    return 0;
}