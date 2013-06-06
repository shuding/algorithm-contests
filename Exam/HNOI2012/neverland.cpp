#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <set>
#define MAXN 100500
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a, b, q, x, y, f1, f2, fa[MAXN];
long long rank[MAXN];
set<pair<long long, int> > k[MAXN];
char cmd; 

void read(long long &n){
	char c = getchar(); n = 0;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
}

int father(int i){
	return fa[i] == i ? i : fa[i] = father(fa[i]);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, n){
		read(rank[i]);
		fa[i] = i;
		k[i].insert(make_pair(rank[i], i));
	}
	rep(i, m){
		scanf("%d%d", &a, &b);
		f1 = father(a);
		f2 = father(b);
		if(f1 != f2){
			k[f1].insert(k[f2].begin(), k[f2].end());
			fa[f2] = f1;
		}
	}
	scanf("%d", &q);
	set<pair<long long, int> >::iterator it;
	while(q--){
		cmd = getchar();
		while(cmd != 'Q' && cmd != 'B') cmd = getchar();
		scanf("%d%d", &x, &y);
		if(cmd == 'Q'){
			x = father(x);
			it = k[x].begin();
			for(int i = 1; i < y && it != k[x].end(); ++i) ++it;
			if(it == k[x].end())
				printf("-1\n");
			else
				cout << (*it).second << endl;
		}
		else{
			f1 = father(x);
			f2 = father(y);
			if(f1 != f2){
				k[f1].insert(k[f2].begin(), k[f2].end());
				fa[f2] = f1;
			}
		}
	}
	return 0;
}
