#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
 
int n, a[101];
int hash[10000000];
long long ans, num[10000000];
 
int calc(long long n){
	int tmp = (unsigned int)n % 9999991;
	while(num[tmp] && num[tmp] != n) ++tmp;
	num[tmp] = n;
	return tmp;
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				hash[calc((long long)a[i] * a[j] + a[k])]++;
	for(int i = 1; i <= n; ++i) if(a[i] != 0)
		for(int j = 1; j <= n; ++j)
			for(int k = 1; k <= n; ++k)
				ans += hash[calc((long long)a[i] * (a[j] + a[k]))];
	cout << ans << endl;
}