#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long n, tot;

long long phi(long long i){
	double s = i;
	for(int j = 2; j <= i; ++j)
		if(i % j == 0){
			s *= (1 - 1 / (double)j);
			while(i % j == 0)
				i /= j;
			j = 2;
		}
	return (long long)s;
}

int main(){
	while(scanf("%lld", &n) != EOF){
		tot = 0;
		for(long long i = 1; i * i <= n; ++i)
			if(n % i == 0)
				tot += phi(n / i) * i + (i * i != n ? phi(i) * n / i : 0);
		cout << tot << endl;
	}
	return 0;
}
