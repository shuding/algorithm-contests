#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define MAXN 1001
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct number{
	long long d[300];
	number operator * (const long long &t) const{
		number c;
		memset(c.d, 0, sizeof(c.d));
		rep(i, d[0])
			c.d[i] = d[i] * t;
		rep(i, d[0]){
			c.d[i + 1] += c.d[i] / 1000000;
			c.d[i] %= 1000000;
		}
		c.d[0] = d[0];
		while(c.d[c.d[0] + 1]){
			c.d[0]++;
			c.d[c.d[0] + 1] += c.d[c.d[0]] / 1000000;
			c.d[c.d[0]] %= 1000000;
		}
		return c;
	}
	number operator + (const number &n) const{
		number c;
		memset(c.d, 0, sizeof(c.d));
		rep(i, d[0])
			c.d[i] = d[i];
		rep(i, n.d[0])
			c.d[i] += n.d[i];
		c.d[0] = max(d[0], n.d[0]);
		rep(i, c.d[0]){
			c.d[i + 1] += c.d[i] / 1000000;
			c.d[i] %= 1000000;
		}
		while(c.d[c.d[0] + 1])
			c.d[0]++;
		return c;
	}
} ans;

int n, m;
number f[2][3][3][MAXN]; // type: teacher, boy, girl; t, b, g.

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n + 3 < m){
		cout << 0 << endl;
		return 0;
	}
	f[0][1][0][0].d[0] = f[0][1][0][0].d[1] = 1;
	rep(tot, n + m + 2)
		for(int t = 0; t <= min(2, tot); ++t)
			for(int b = 0; b <= min(n, tot - t); ++b){
				int g = tot - t - b;
				memset(f[tot & 1][0][t][b].d, 0, sizeof(f[tot & 1][0][t][b].d));
				memset(f[tot & 1][1][t][b].d, 0, sizeof(f[tot & 1][1][t][b].d));
				memset(f[tot & 1][2][t][b].d, 0, sizeof(f[tot & 1][2][t][b].d));
				if(t > 0)
					f[tot & 1][0][t][b] = (f[!(tot & 1)][1][t - 1][b] + f[!(tot & 1)][2][t - 1][b]) * t;
				if(b > 0)
					f[tot & 1][1][t][b] = (f[!(tot & 1)][0][t][b - 1] + f[!(tot & 1)][1][t][b - 1] + f[!(tot & 1)][2][t][b - 1]) * b;
				if(g > 0)
					f[tot & 1][2][t][b] = (f[!(tot & 1)][0][t][b] + f[!(tot & 1)][1][t][b]) * g;
			}
	ans = f[(n + m + 2) & 1][0][2][n] + f[(n + m + 2) & 1][1][2][n];
	ans = ans + f[(n + m + 2) & 1][2][2][n];
	rep(i, ans.d[0]){
		int dit = ans.d[0] - i + 1;
		if(i > 1){
			if(ans.d[dit] < 100000) cout << 0;
			if(ans.d[dit] < 10000) cout << 0;
			if(ans.d[dit] < 1000) cout << 0;
			if(ans.d[dit] < 100) cout << 0;
			if(ans.d[dit] < 10) cout << 0;
		}
		cout << ans.d[dit];
	}
	if(!ans.d[0]) cout << 0;
	cout << endl;
	return 0;
}
