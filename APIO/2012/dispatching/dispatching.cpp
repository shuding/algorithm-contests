/*
*
*   Copyright (C) 2012 All rights reserved.
*   File name:  dispatching.cpp
*   Author:     Parabola_ds
*   Creat time: 2012.05.18
*
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#define MAXN 100050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = ~0U >> 1;

class treap{
private:
	struct node{
		int C, L, key, size;
		long long sum;
		node(int _c, int _l, node *n){
			C = _c;
			L = _l;
			key = rand() - 1;
			c[0] = c[1] = n;
			size = 1;
			sum = _c;
		}
		void rz(){
			size = c[0]->size + c[1]->size + 1;
			sum = c[0]->sum + c[1]->sum + C;
		}
		node *c[2];
	} *root, *null;
	void rot(node *&t, bool d){
		node *c = t->c[d];
		t->c[d] = c->c[!d];
		c->c[!d] = t;
		t->rz();
		c->rz();
		t = c;
	}
	void ins(node *&t, int C, int L){
		if(t == null){
			t = new node(C, L, null);
			return;
		}
		bool d = C > t->C;
		ins(t->c[d], C, L);
		if(t->c[d]->key < t->key)
			rot(t, d);
		else
			t->rz();
	}
	void uni(node *&n, treap &t){
		if(n == null) return;
		t.Insert(n->C, n->L);
		uni(n->c[0], t);
		uni(n->c[1], t);
	}
	long long calc(node *&t, int &m){
		if(t->sum <= m){
			m -= t->sum;
			return t->size;
		}
		long long ret = 0;
		ret += calc(t->c[0], m);
		if(t->C <= m)
			ret++, m -= t->C;
		ret += calc(t->c[1], m);
		return ret;
	}
public:
	treap(){
		null = new node(0, 0, 0);
		null->size = null->sum = 0;
		null->key = inf;
		root = null;
	}
	void Insert(int C, int L){
		ins(root, C, L);
	}
	int Size(){
		return root->size;
	}
	void Union(treap &t){
		uni(root, t);
	}
	long long GetAns(int m){
		return calc(root, m);
	}
} t[MAXN];

long long ans;
int n, m, b, c[MAXN], l[MAXN];
vector<int> e[MAXN];

void solve(int root){
	int T = root;
	t[T].Insert(c[root], l[root]);
	for(vector<int>::iterator it = e[root].begin(); it != e[root].end(); ++it){
		solve(*it);
		if(t[*it].Size() < t[T].Size())
			t[*it].Union(t[T]);
		else
			t[T].Union(t[*it]), T = *it;
	}
	ans = max(ans, t[T].GetAns(m) * (long long)l[root]);
	t[root] = t[T];
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	rep(i, n){
		scanf("%d%d%d", &b, &c[i], &l[i]);
		e[b].push_back(i);
	}
	solve(0);
	cout << ans << endl;
	return 0;
}

