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
} a[MAXN + 10];

int n, m, tot;

struct divTree{
	int l, r, m;
	divTree *c[2];
	vector<data> v;
	void update(){
		vector<data>::iterator top1 = c[0]->v.begin(), top2 = c[1]->v.begin();
		while(top1 != c[0]->v.end() || top2 != c[1]->v.end()){
			if(top1 == c[0]->v.end() || (top2 != c[1]->v.end() && top1->id > top2->id)){
				v.push_back(*top2); top2++;
				if(v.size() >= 2)
					v[v.size() - 1].s = v[v.size() - 2].s;
			}
			else{
				v.push_back(*top1); top1++;
				v[v.size() - 1].s = 1;
				if(v.size() >= 2)
					v[v.size() - 1].s += v[v.size() - 2].s;
			}
		}
	}
	void build(int L, int R){
		l = L; r = R; v.clear();
		if(l == r){
			v.push_back(a[++tot]);
			return;
		}
		m = (l + r) / 2;
		c[0] = new divTree();
		c[1] = new divTree();
		c[0]->build(l, m);
		c[1]->build(m + 1, r);
		update();
	}
	int query(int L, int R, int k){
		if(L == R) return v[R - 1].n;
		int ls = L >= 2 ? v[L - 2].s : 0, rs = R >= 1 ? v[R - 1].s : 0;
		if(rs - ls >= k)
			return c[0]->query(ls + 1, rs, k);
		else
			return c[1]->query(L - ls, R - rs, k - rs + ls);
	}
} root;

int main(){
	while(scanf("%d%d", &n, &m) == 2){
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i].n);
			a[i].s = 0; a[i].id = i;
		}
		sort(a + 1, a + 1 + n);
		root.build(1, n);
		int l, r, k;
		while(m--){
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", root.query(l, r, k));
		}
	}
	return 0;
}
