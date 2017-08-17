#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int m,n,k;
	cin>>m>>n>>k;
	int result1;
	int result2;
	char result3;
	if(k&1) result3 = 'L';
	else result3 = 'R';
	//above all are right
	result1 = (k-1)/(2*n) +1;
	//compute result1
	result2 = ((k-((result1-1)*2*n))-1)/2 + 1;
	//compute result2
	cout<<result1<<' '<<result2<<' '<<result3<<endl;
	//output
	return 0;
}