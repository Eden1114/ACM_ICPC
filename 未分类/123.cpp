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
const int inf = 0x3f3f3f3f;
char s[104];
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    gets(s);
    int len = strlen(s);
    int r = 0,b = 0,y = 0,g = 0;
    bool flagr ,flagy,flagb,flagg;
    flagr = flagy = flagb = flagg = true;
    for(int i  = 0;i < len;i++)
    {
        if(flagr && s[i] == 'R')
        {
            for(int j = i % 4;j < len; j += 4)
            {
                if(s[j] == '!')
                {
                    s[j] = 'R';
                    r++;
                }
                flagr = false;
            }
        }
        
        if(flagb && s[i] == 'B')
        {
            for(int j = i % 4;j < len; j += 4)
            {
                if(s[j] == '!')
                {
                    s[j] = 'B';
                    b++;
                }
                flagb = false;
                
            }
        }
        
        if(flagy && s[i] == 'Y')
        {
            for(int j = i % 4;j < len; j += 4)
            {
                if(s[j] == '!')
                {
                    s[j] = 'Y';
                    y++;
                }
                flagy = false;
            }
        }
        if(flagg && s[i] == 'G')
        {
            for(int j = i % 4;j < len; j += 4)
            {
                if(s[j] == '!')
                {
                    s[j] = 'G';
                    g++;
                }
            flagg = false;
        }
    } 
        
        if(flagb == false && flagr == false && flagy == false && flagg == false)
        break;
    }
    
    printf("%d %d %d %d\n",r,b,y,g);
    
    return 0;
}