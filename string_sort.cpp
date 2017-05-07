/*
string_sort
Question:to make the max number by link some numbers.
Eg: 989 998 99 -> 99998989
Method：Greedy
The Haredest Part:how to greed
if a+b > b+a:
     return true
else:
    return false
other：
use vector
use iterator
use sort
use compare function

I shall write code more cpp..
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
bool compare(string a,string b){
    if (a+b > b+a) return true;
    else return false;
    
}
int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    for(int i = 1;i <= T;i++)
    {
        vector<string> data;
        int n;
        cin>>n;
        
        for(int j = 0;j < n;j++)
        {
            string a;
            cin>>a;
            data.push_back(a);
        }
        
        sort(data.begin(), data.end(),compare);
        
        vector<string>::iterator iter;
        cout<<"Case #"<<i<<": ";
        for(iter = data.begin();iter != data.end();iter++)
        {
            cout<< *iter;
        }
        putchar('\n');
    }
    return 0;
}
