#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 65537 * 2
#define CL(x) (2 * x - 1)		// close left
#define OL(x) (2 * x)			// open left
#define CR(x) (2 * x - 1)		// close right
#define OR(x) (2 * x - 2)		// open right
using namespace std;

bool empty_set = 1;

struct set{
	bool empty;
	int l, r;
	set(){}
	set(bool e, int l, int r): empty(e), l(l), r(r){}
	inline void init(){
		if(l == r && !(l & 1))
			empty = 0;
		else
			empty = (l > r);
	}
	inline void print(){
		if(!empty){
			printf("%c%d,%d%c ", l & 1 ? '[' : '(', (l + 1) / 2 - 1, r / 2, r & 1 ? ']' : ')');
			empty_set = 0;
		}
	}
	inline void U(set s){
		if(s.empty) return;
		if(empty) l = s.l, r = s.r, empty = 0;
		else r = s.r;
	}
};

struct command{
	int type;
	set s;
	inline bool read(){
		char c = getchar(), l, r;
		s.l = s.r = 0;
		while(c != 'U' && c != 'I' && c != 'D' && c != 'C' && c != 'S' && c != EOF)
			c = getchar();
		if(c == EOF) return 0;
		switch(c){
			case 'C': type = 4; break;
			case 'D': type = 3; break;
			case 'I': type = 2; break;
			case 'S': type = 5; break;
			case 'U': type = 1; break;
		}
		while(c != '[' && c != '(') c = getchar();
		l = c;
		while(c < '0' || c > '9') c = getchar();
		while(c >= '0' && c <= '9'){
			s.l = s.l * 10 + c  - '0';
			c = getchar();
		}
		while(c < '0' || c > '9') c = getchar();
		while(c >= '0' && c <= '9'){
			s.r = s.r * 10 + c  - '0';
			c = getchar();
		}
		while(c != ']' && c != ')') c = getchar();
		r = c;
		s.l++; s.r++;		// for s.l == 0, shr
		s.l = l == '[' ? CL(s.l) : OL(s.l);
		s.r = r == ']' ? CR(s.r) : OR(s.r);
		s.init();
		return 1;
	}
} cmd;

struct segment_tree{
	int l, r;
	bool empty, full;
	segment_tree *c[2];
	inline void build(int L, int R){
		l = L; r = R; empty = 1; full = 0;
		if(L == R) return;
		c[0] = new segment_tree;
		c[1] = new segment_tree;
		int mid = L + R >> 1;
		c[0]->build(L, mid);
		c[1]->build(mid + 1, R);
	}
	inline set left_set(){
		if(empty) return set(1, 0, 0);
		if(full) return set(0, l, r);
		set l1 = c[0]->left_set();
		int mid = l + r >> 1;
		if(!l1.empty && l1.r == mid){
			set l2 = c[1]->left_set();
			l1.U(l2);
		}
		return l1;
	}
	inline set right_set(){
		if(empty) return set(1, 0, 0);
		if(full) return set(0, l, r);
		set r1 = c[1]->right_set();
		int mid = l + r >> 1;
		if(!r1.empty && r1.l == mid + 1){
			set r2 = c[0]->right_set();
			r2.U(r1);
			return r2;
		}
		return r1;
	}
	inline void print(){
		if(empty || full) return;
		c[0]->print();
		set sl = c[0]->right_set(), sr = c[1]->left_set();
		sl.U(sr);
		if(sl.l > l && sl.r < r) sl.print();
		c[1]->print();
	}
	void U(int L, int R, bool d){
		if(l == L && r == R){
			full = d;
			empty = !d;
			return;
		}
		if(empty){
			c[0]->empty = c[1]->empty = 1;
			c[0]->full = c[1]->full = 0;
		}
		if(full){
			c[0]->full = c[1]->full = 1;
			c[0]->empty = c[1]->empty = 0;
		}
		int mid = l + r >> 1;
		if(R <= mid || L > mid) c[L > mid]->U(L, R, d);
		else{
			c[0]->U(L, mid, d);
			c[1]->U(mid + 1, R, d);
		}
		empty = c[0]->empty & c[1]->empty;
		full = c[0]->full & c[1]->full;
	}
	inline void I(int L, int R){
		U(0, L - 1, 0);
		U(R + 1, MAX, 0);
	}
	inline void D(int L, int R){
		U(L, R, 0);
	}
	inline void S(int L, int R){
		if(l == L && r == R && (empty || full)){
			swap(empty, full);
			return;
		}
		if(empty){
			c[0]->empty = c[1]->empty = 1;
			c[0]->full = c[1]->full = 0;
		}
		if(full){
			c[0]->full = c[1]->full = 1;
			c[0]->empty = c[1]->empty = 0;
		}
		int mid = l + r >> 1;
		if(R <= mid || L > mid) c[L > mid]->S(L, R);
		else{
			c[0]->S(L, mid);
			c[1]->S(mid + 1, R);
		}
		empty = c[0]->empty & c[1]->empty;
		full = c[0]->full & c[1]->full;
	}
	inline void C(int L, int R){
		U(0, L - 1, 0);
		U(R + 1, MAX, 0);
		S(L, R);
	}
} T;

int main(){
	T.build(0, MAX);
	while(cmd.read())
		switch(cmd.type){
			case 1: if(!cmd.s.empty) T.U(cmd.s.l, cmd.s.r, 1); break;
			case 2: if(!cmd.s.empty) T.I(cmd.s.l, cmd.s.r); break;
			case 3: if(!cmd.s.empty) T.D(cmd.s.l, cmd.s.r); break;
			case 4: if(!cmd.s.empty) T.C(cmd.s.l, cmd.s.r); break;
			case 5: if(!cmd.s.empty) T.S(cmd.s.l, cmd.s.r); break;
		}
	set s = T.left_set();
	s.print();
	T.print();
	s = T.right_set();
	s.print();
	if(empty_set)
		printf("empty set");
	printf("\n");
	return 0;
}