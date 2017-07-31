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

#define F(i,a,b) for(int i = a; i < b; i++)

using namespace std;

const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

const int maxn = 100 + 6;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];
int cnt = 0;


void dfs(int r,int c,int id)
{
    if(r < 0 || r>= m || c < 0 || c >= n) return;
    if(idx[r][c] > 0 || pic[r][c] != 'W') return;
    idx[r][c] = id;
    for(int dr = -1;dr <= 1;dr++)
    {  
        for(int dc = -1;dc <= 1;dc++)
        {
               if (dr != 0 || dc != 0) 
               {
                   dfs(r+dr, c+dc, id);
               }
        }
    }
}


int main(/*int argc, char *argv[]*/) {
	ios::sync_with_stdio(false);
    
    cin>>m>>n;
    
    for(int i = 0;i < m;i++) scanf("%s",pic[i]);

    
    memset(idx,0, sizeof(idx));
    
    
    
    for(int i = 0;i < m;i++)
    
        for(int j = 0;j < n;j++)
            
            if(idx[i][j] == 0 && pic[i][j] == 'W')
                
                dfs(i,j,++cnt);
            
        
    

    
    cout<<cnt<<endl;    
	return 0;
}