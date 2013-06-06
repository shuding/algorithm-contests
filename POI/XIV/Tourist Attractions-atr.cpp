#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXN 20005
#define MAXM 400005
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = ~0U >> 2;

struct edge{
	int t, w, next;
	edge(){}
	edge(int t, int w, int n): t(t), w(w), next(n){}
} e[MAXM];

int n, m, k, etop, st[MAXN], ans = inf;

void add(int s, int t, int w){
	e[++etop] = edge(t, w, st[s]);
	st[s] = etop;
}

int dis[MAXN], que[MAXN * 20], res[25];
bool v[MAXN];

void spfa(int S, int *dis){
	rep(i, n){
		v[i] = 0;
		dis[i] = inf;
	}
	dis[S] = 0; v[S] = 1;
	int p = 0, q = 0;
	que[0] = S;
	while(p <= q){
		for(int i = st[que[p]]; i; i = e[i].next)
			if(dis[e[i].t] > dis[que[p]] + e[i].w){
				dis[e[i].t] = dis[que[p]] + e[i].w;
				if(!v[e[i].t])
					que[++q] = e[i].t;
				v[e[i].t] = 1;
			}
		v[que[p++]] = 0;
	}
}

int g[25][25], f[21][1 << 19];

inline void zip(int T, int &state){
	state = ((state >> T) << (T - 1)) | (state & ((1 << T) - 1));
}

int dfs(int v, int state){
	int _state = state;
	zip(v - 1, state);
	if(f[v - 1][state]) return f[v - 1][state];
	if((_state & res[v]) != res[v]){
		f[v - 1][state] = inf;
		return inf;
	}
	if(!state){
		f[v - 1][state] = g[1][v];
		return g[1][v];
	}
	int calc = inf;
	rep(i, k){
		int SHL_VAL = (1 << (i - 1));
		if(_state & SHL_VAL)
			calc = min(calc, dfs(i + 1, _state - SHL_VAL) + g[i + 1][v]);
	}
	f[v - 1][state] = calc;
	return calc;
}

inline void read(int &n){
	char c = getchar(); n = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i, m){
		int s, t, w;
		read(s); read(t); read(w);
		add(s, t, w); add(t, s, w);
		if(s <= k + 1 && t <= k + 1)
			g[s][t] = g[t][s] = g[t][s] ? min(g[t][s], w) : w;
	}
	int Q, A, B;
	scanf("%d", &Q);
	while(Q--){
		scanf("%d%d", &A, &B);
		res[B] |= (1 << (A - 2));				// A should be visited before B
	}
	rep(i, k + 1){
		spfa(i, dis);
		rep(j, k)
			g[i][j + 1] = g[j + 1][i] = dis[j + 1];
		g[i][k + 2] = g[k + 2][i] = dis[n];
	}
	n = k + 2;

	int INIT_STATE = (1 << k) - 1;
	rep(i, k)
		ans = min(ans, dfs(i + 1, INIT_STATE - (1 << (i - 1))) + g[i + 1][n]);	
	if(!k)
		ans = g[1][n];
	printf("%d\n", ans);
	return 0;
}

