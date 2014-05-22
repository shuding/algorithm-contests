#include <iostream>
#include <cstdio>
using namespace std;

int n;
double tot;

int main(){
	scanf("%d", &n);
	tot = n;
	for(int i = 2; i <= n; ++i)
		if(n % i == 0){
			tot *= (1.0 - 1.0 / i);
			while(n % i == 0)
				n /= i;
		}
	printf("%.0lf\n", tot);
}

