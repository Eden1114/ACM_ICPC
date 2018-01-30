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

const int maxm = 100;
const int maxn = 100;
int field[maxm][maxn];
int m = 4;//棋盘长
int n = 4;//棋盘的宽
int scores= 0;//得分


/*
 * 数据初始化
 */
void Init()
{
    scores = 0;
    //field = new int[m][n];
    memset(field, 0, sizeof(field));
}


void Calculate(char input)
{
    if(input == 'S' || input == 's')
    {
        int i,j,t;
        for(j = 0; j < n; j++)
            for(i = m - 1; i > 0; i--)
                if(field[i][j] && field[i][j] == field[i - 1][j])
                {
                    scores += field[i][j];
                    field[i][j] <<= 1;
                    field[i - 1][j] = 0;
                }
            
        
        for(j = 0; j < n; j++)
        {
            for(i = m -1; i > 0; i--)
            {
                if(field[i][j] == 0)
                    for(t = i -1;t >= 0;t--)
                    {
                        
                    }
            }        
        }
    }
    if(input == 'W' || input == 'w')
    {
        int i,j;
        for(j = 0; j < n; j++)
            for(i = 0; i < m - 1; i++)
                if(field[i][j] && field[i][j] == field[i + 1][j])
                {
                    scores += field[i][j];
                    field[i][j] <<= 1;
                    field[i + 1][j] = 0;
                }
            
        
        for(j = 0; j < n; j++)
            for(i = 0; i < m - 1; i++)
                if (field[i][j] == 0)
                    swap(field[i][j],field[i+1][j]);
    }
}



int Value(int i, int j)
{
    if(i < 0 || i >= m || j < 0 || j >= n)
        return -1;
    return field[i][j];
}


/*
	判断会不会结束游戏
 */
bool is_dead()
{
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < 4;k++)
            {
                if(Value(i + dx[k], j + dy[k]) == field[i][j])
                    return false;
            }
        }
    }
    
    return true;
}





int rands()
{
    int x[m * n],y[m * n];
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(field[i][j] == 0)
            {
                x[cnt] = i;
                y[cnt++] = j;
            }
        }	
    }
    
    srand((unsigned)time(NULL));
    
    int t = rand() % (cnt - 1);
    int p = (rand() % 2 + 1) * 2;
    
    field[x[t]][y[t]] = p;
    return 0;
}




void print()
{
    system("clear");
    printf("-------------------------\n");
    for(int i = 0; i < m;i++)
    {
        putchar('|');
        for(int j = 0;j < n;j++)
        {
            printf(" %-5d",field[i][j]);
        }
        putchar('|');
        putchar('\n');
    }
    printf("-------------------------\n");
}


int play()
{
    char ch;
    while(1)
    {
        printf("Press any key to start the game:");
        ch = getchar();
        while(getchar()!= '\n');
        if(ch == 'Q' || ch == 'q') return 0;
        Init();
        //初始化
        char input;
        while(1)
        {
            
            if(is_dead())
            {
                break;
            }
            bool flag = true;
            if(flag)
            {
                rands();//随机生成位置)
                flag = false;
            }
            print();
            input = getchar();
            while(getchar()!= '\n');
            Calculate(input);
        }
    }
}




int main()
{
    play();
    return 0;
}
