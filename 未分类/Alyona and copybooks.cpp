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
	long long n,a,b,c;
	cin>>n>>a>>b>>c;
	// a 1   b  2  c 3
	long long need_to_buy = n%4;
	long long result;
	if(need_to_buy == 0) result = 0;
	else if(need_to_buy == 3){
		if(a <= b + c && a <= 3 * c)  result = a;
		else if(b + c <= 3 * c) result = b + c;
		else result = 3 * c;
	}
	else if(need_to_buy == 2){
		if(2 * a <= b && 2 * a <= 2 * c) result = 2 * a;
		else if(b <= 2 * c) result = b;
		else result = 2 * c;
	}
	else if(need_to_buy == 1){
		if(c <= 3 * a && c <= a+b) result = c;
		else if(3 * a <= a + b) result = 3 * a;
		else result = a + b;
	}
	printf("%lld\n",result);
	return 0;
}