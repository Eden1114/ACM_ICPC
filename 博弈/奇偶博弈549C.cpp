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

int n,k;
int x;
int odd,even;
bool flag;

//D和S都是一个奇数，一个偶数的去选择

int main(/*int argc, char *argv[]*/) {
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);  
//    freopen("out.txt","w",stdout);
    cin >> n >> k;
    for(int i = 0;i < n;i++)
    {
        cin >> x;
        if(x % 2) {
            odd++;
        }else {
            even++;
        }
    }
    //cout << odd <<' ' << even<< ' '<<n-k<<endl ;
    if(n == k) {
        //直接判断
        if(odd % 2) flag = false;
        else flag = true;
    }
    else {
        int op = n - k - 1;
        if((n-k) % 2) {
            
            op /= 2;
            //操作奇数次，最后是S操作
            if(even > op && odd > op) {
                //最后一次操作时，剩下的数有奇数也有偶数
                flag =false;
            }
            
            else if(even <= op && (odd - (2 * op - even)) % 2 == 0) {
                //最后一次操作的数字只有奇数，且奇数个数为偶数个
                flag = false;
            }
            
            else flag = true;
        }
        else {
            //最后一次操作是D.
            //要想S赢，必须剩下偶数个奇数
            op /= 2;
            op++;
            if(even <= op && (odd - ( op * 2 - 1 - even)) % 2 == 0)  
                     flag = false;
            else flag = true;
        }
    }
    
    if(flag) cout << "Daenerys" <<endl;
    else cout << "Stannis" <<endl;
    
    return 0;
}