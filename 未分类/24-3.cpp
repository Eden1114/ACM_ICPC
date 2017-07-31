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
const int maxn = 800000 + 5;

vector<pair<int, int> > j;

bool compare(const pair<int, int> &a,const pair<int, int> &b)
{
    return a.second < b.second;
}

int main(/*int argc, char *argv[]*/) {
    ios::sync_with_stdio(false);
    int n;cin>>n;
    int ans = 0,sum = 0;
    pair<int, int> temppair;
    F(n)
    {
        cin>>temppair.first>>temppair.second;
        j.push_back(temppair);
    }
    
    sort(j.begin(),j.end(),compare);
    /*
    
    */
    
    priority_queue< pair<int,int> > p_que;
    
    for(int i = 0; i < n;i++)
    {
        //先加进去，再判断要不要出来
        sum += j[i].first;
        p_que.push(j[i]);
        if(sum > j[i].second)
        {
            sum -= p_que.top().first;
            p_que.pop();
        }
        
        //
    }
    cout<<p_que.size()<<endl;
    return 0;
}