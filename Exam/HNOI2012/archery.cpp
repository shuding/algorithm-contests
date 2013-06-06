#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAXN 100050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const double inf = 1e15, eps = 1e-5;

int n;
double X, Y1, Y2;
double t1, t2, u, d, BETA[MAXN], ALPHA[MAXN], GAMA[MAXN];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	rep(i, n){
		scanf("%lf%lf%lf", &X, &Y1, &Y2);
		ALPHA[i] = 1.0 / X;
		BETA[i] = Y1 / (X * X);
		GAMA[i] = Y2 / (X * X);
	}
	u = inf;
	d = -inf;
	rep(i, n){
		d = max(d, BETA[i] / ALPHA[i]);
		rep(j, i - 1){
			t1 = (GAMA[j] - BETA[i]) / (ALPHA[j] - ALPHA[i]);
			t2 = (BETA[j] - GAMA[i]) / (ALPHA[j] - ALPHA[i]);
			if(t1 > t2) swap(t1, t2);
			u = min(u, t2);
			d = max(d, t1);
		}
		if(d > u + eps){
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}
