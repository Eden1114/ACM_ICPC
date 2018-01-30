#include <cstdio>
#include <iostream>
#include <queue>
/*
 BFS,广度优先搜索
 题意：给定一个大小为N*M的迷宫。迷宫由通道和墙壁组成。
 每一步可以向邻近的上下左右4格的通道移动。请求出从起点
 到终点所需的最小步数。请注意，本题假定从起点一定合一移动到终点。
 限制条件N,M <= 100
 输入样例：
 N = 10 M = 10
 #S########
 .....
 .....
 .....#..G#
 分析：
 只实现了一部分BFS的核心代码
 使用了pair类型（std::pair）
 使用了queue构造队列，进行BFS
 */
const int INF = 100000000;
const int MAX_N = 100;
const int MAX_M = 100;
using namespace std;
typedef pair<int,int> P;
char maze[MAX_N][MAX_M+1];
int N,M;
int sx,sy;
int gx,gy;
int d[MAX_N][MAX_M + 1];
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
int bfs()
{
    queue<P> que;
    for(int i = 0; i < N;i++)
    {
        for(int j = 0;j < M;j++)
            d[i][j] =INF;
    }
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    while(que.size())
    {
        P p = que.front();que.pop();
        if(p.first == gx && p.second == gy) break;
        for(int i = 0;i < 4;i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny &&ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
            {
                que.push(P(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}
int main()
{
    int res = bfs();
    printf("%d\n",res);
    return 0;
}