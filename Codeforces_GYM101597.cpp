/*
 *题号：
 *时间：
 *解题思想：
 *
 */
//include <bits/stdc++.h>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <cstring>
#include <climits>
#include <limits>
#include <string>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <list>
#include <map>
#include <set>

const double eps=1e-8,pi=acos(1.0*(-1));
const int INF=0x3f3f3f3f,mod=1e9+7;
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

typedef std::pair<int,int> P;
typedef long long LL;
typedef long long ll;
using namespace std;

typedef struct point {
    double x,y;
    double len;
} Point;

Point A,B,C;

double getLen(Point X, Point Y) {
    double dx = abs(X.x - Y.x);
    double dy = abs(X.y - Y.y);
    return sqrt(dx * dx + dy * dy);
}

double getS(Point a, Point b,Point c) {
    double t = a.x * b.y;
        t += b.x * c.y;
        t += c.x * a.y;
        t -= a.x * c.y;
        t -= b.x * a.y;
        t -= c.x * b.y;
        t /= 2;
        if(t > 0) return t;
        else return -t;
}

Point getCondix(Point &A, Point &B, double dis) {
    A.len = getLen(A, B);
    double rate = dis / A.len;
    //cout << rate << endl;
    Point C = A;
    Point T;
    T.x =  (B.x - A.x);
    T.y =  (B.y - A.y);
    
    C.x += rate * (B.x - A.x);
    C.y += rate * (B.y - A.y);
    return C;
}
bool vis[12];
int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    
    double ans = -1;
    Point Points[12];
    
    {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            double dis;
            cin >> dis;
            if(i == 0) {
                Points[0] = getCondix(A, B, dis);
                vis[0] = true;
            } 
            else if(i == 1) {
                Points[1] = getCondix(A, B, dis);
                vis[1] = true;
            }
            
            else if(i == n - 2) {
                Points[2] = getCondix(A, B, dis);
                vis[2] = true;
            }
            else if(i == n - 1) {
                Points[3] = getCondix(A, B, dis);
                vis[3] = true;
            }
        }
    }
    
    {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            double dis;
            cin >> dis;
            if(i == 0) {
                Points[4] = getCondix(B, C, dis);
                vis[4] = true;
            } 
            else if(i == 1) {
                Points[5] = getCondix(B, C, dis);
                vis[5] = true;
            }
            
            else if(i == n - 2) {
                Points[6] = getCondix(B, C, dis);
                vis[6] = true;
            }
            else if(i == n-1){
                Points[7] = getCondix(B, C, dis);
                vis[7] = true;
            }
        }
    }
    
    {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
            double dis;
            cin >> dis;
            if(i == 0) {
                Points[8] = getCondix(C, A, dis);
                vis[8] = true;
            } 
            else if(i == 1) {
                Points[9] = getCondix(C, A, dis);
                vis[9] = true;
            }
            
            else if(i == n - 2) {
                Points[10] = getCondix(C, A, dis);
                vis[10] = true;
            }
            else if(i == n-1){
                Points[11] = getCondix(C, A, dis);
                vis[11] = true;
            }
        }
    }
    
    double S;
    for(int i = 0;i < 12;i++)
    {
        for(int j = i+1;j < 12;j++)
        {
            for(int k = j+1;k < 12;k++)
            {
                if(vis[i] && vis[j] && vis[k])
                {
                    S = getS(Points[i], Points[j], Points[k]);
//                    cout << S << endl;
//                    cout << i << endl;
//                    cout << j << endl;
//                    cout << k << endl;
//                    cout << endl;
                    ans = max(ans, S);
                }
            }
        }
    }
    
//    cout << Points[1].x << ' ' << Points[1].y << endl;
//    cout << Points[3].x << ' ' << Points[3].y << endl;
//    cout << Points[5].x << ' ' << Points[5].y << endl;
    
    printf("%.7lf\n", ans);
    return 0;
}