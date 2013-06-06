#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#define MAXN 100000
using namespace std;

struct data{
	int n, s, id;
	bool operator < (const data &d) const{
		return n < d.n;
	}
} a[MAXN + 10], b[20][MAXN + 10];

int n, m, tot, top, tn;

void update(int n, int l, int r){
	int m = (l + r) / 2;
	int top1 = l, top2 = m + 1, top = l;
	while(top1 != m + 1 || top2 != r + 1)
		if(top1 == m + 1 || (top2 !=r + 1 && b[n + 1][top1].id > b[n + 1][top2].id)){
			b[n][top++] = b[n + 1][top2++];
			b[n][top - 1].s = 0;
			if(top > l + 1)
				b[n][top - 1].s += b[n][top - 2].s;
		}
		else{
			b[n][top++] = b[n + 1][top1++];
			b[n][top - 1].s = 1;
			if(top > l + 1)
				b[n][top - 1].s += b[n][top - 2].s;
		}
}

void build(int n, int L, int R){
	if(L == R){
		b[n][L] = a[++tot];
		return;
	}
	int m = (L + R) / 2;
	build(n + 1, L, m);
	build(n + 1, m + 1, R);
	update(n, L, R);
}

int query(int n, int L, int R, int l, int r, int k){
	if(l == r) return b[n][l].n;
	int ls = l > L ? b[n][l - 1].s : 0, rs = r >= L ? b[n][r].s : 0, m = (L + R) / 2;
	if(rs - ls >= k)
		return query(n + 1, L, m, ls + L, rs + L - 1, k);
	else
		return query(n + 1, m + 1, R, l - L - ls + m + 1, r - L + 1 - rs + m, k - rs + ls);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i].n);
		a[i].s = 0; a[i].id = i;
	}
	sort(a + 1, a + 1 + n);
	build(0, 1, n);
	int l, r, k;
	while(m--){
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(0, 1, n, l, r, k));
	}
	return 0;
}
