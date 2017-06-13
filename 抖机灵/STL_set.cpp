/*
STL_set
Question:
    HDU6019
    http://blog.csdn.net/qq_27437781/article/details/68951480
Method：STL_container_set
The Haredest Part:
    You should konw something about it..

Hardest Part：
set<int> data;
data.count(n)
//To check if n in set data.
data.clear();
//To make the set data empty.
data.empty()
//To check if the set data is empty.
data.insert(n)
//To insert n to set data.

Other:
    http://www.cnblogs.com/wonderKK/archive/2012/04/10/2441379.html
set is similar with the concept in mathmatics.
By using Red-Black Tree ,set is really fast to insert,find and delete.
Some Methods of set:
set.begin()
// return the first element of the set.
set.end()
// return the last element of the set.
set.empty()
// to check if the set is empty.
set.insert()
// to insert an element to the set.
set.erase()
//to delete an element to the set.
s,size()
// to return the number of elements of the set.

*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <set>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    set<int> data;
    while(T--)
    {
        int res = 0;
        
        int n;
        cin>>n;
        
        int temp;
        
        for(int i = 0; i < n;i++)
        {
            cin>>temp;
            
            if(i == 0||data.count(temp) == 1)
            {
                res++;
                data.clear();
            }
            
            data.insert(temp);
  
        }
        cout<<res<<endl;
    }
    return 0;
}