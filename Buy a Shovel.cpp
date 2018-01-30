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
	int k,r;
	cin>>k>>r;
	int temp = k;
	int result = 1;
	while(temp < 10)
	{
		if(temp == r) break;
		else {temp += k;result++;}
	}
	if(temp > 10)
	{
		while(temp%10 != 0 && temp%10 != r)
		{
			temp += k;
			result++;
		}
	}
	printf("%d\n",result);
	return 0;
}
