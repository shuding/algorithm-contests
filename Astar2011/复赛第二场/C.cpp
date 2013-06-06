/*
* Copyright (C) 2012 All rights reserved.
* File name:  C.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.17
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = ~0U >> 1;

set<int> n;
char bd[600];
int maxl, len, space, t;
long long num;
bool tt[600];

void ps(){ rep(i, space) printf(" "); }

int S[600];

void solve(){
	space = 4;
	int m = 0, fst = 0;
	int num;
	for(int i = 0; i <= maxl;){
		int j, tmp;
		bool bl;
		m++;
		switch(bd[i]){
			case '3':
				fst++;
				ps(); printf("for (int r%d = 0; r%d < ", fst - 1, fst - 1);
				num = 0;
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				for(; bd[j] >= '0' && bd[j] <= '9' && j <= maxl; ++j)
					num = num * 10 + bd[j] - '0';
				printf("%d; r%d++)", num, fst - 1);
				if(tt[m]) printf(" {");
				puts("");
				space += 4;
				i = j + 1;
				break;
			case '2':
				ps(); printf("if (");
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				for(; bd[j] >= '0' && bd[j] <= '9' && j <= maxl; ++j)
					num = num * 10 + bd[j] - '0';
				if(bl) printf("r%d ", num); else printf("%d ", num);
				i = j + 1;
				if(bd[i] == '1') printf("== "); else if(bd[i] == '2') printf("< "); else printf("> ");
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				for(; bd[j] >= '0' && bd[j] <= '9' && j <= maxl; ++j)
					num = num * 10 + bd[j] - '0';
				if(bl) printf("r%d ", num); else printf("%d ", num);
				i = j + 1;
				break;
			case '1':
				ps();
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				for(; bd[j] >= '0' && bd[j] <= '9' && j <= maxl; ++j)
					num = num * 10 + bd[j] - '0';
				if(bl) printf("r%d =", num);
				i = j + 1;
				num = 0; bl = bd[i] == '#';
				j = i + (bd[i] == '#' ? 1 : 0);
				for(; bd[j] >= '0' && bd[j] <= '9' && j <= maxl; ++j)
					num = num * 10 + bd[j] - '0';
				if(bl) printf(" r%d ", num); else printf(" %d ", num);
				i = j + 1;
				if(bd[i] == '1') printf("+"); else if(bd[i] == '2') printf("-"); else if(bd[i] == '3') printf("*"); else printf("/");
				tmp = i;
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				for(; bd[j] >= '0' && bd[j] <= '9' && j <= maxl; ++j)
					num = num * 10 + bd[j] - '0';
				if(bl) printf(" r%d;\n", num); else printf(" %d;\n", num);
				i = j + 1;
				break;
			case '0':
				space -= 4;
				i++;
				fst--;
				if(tt[m]) ps(), printf("}\n");
				break;
		}
	}
}

int main(){
	cin.getline(bd, 600);
	len = strlen(bd);
	int m = 0, fst = 0;
	for(int i = 0; i < len;){
		int j, tmp;
		bool bl;
		m++;
		switch(bd[i]){
			case '3':
				S[++fst] = m;
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				if(j >= len){
					maxl = i; goto st;
				}
				maxl = j;
				for(; bd[j] >= '0' && bd[j] <= '9'; ++j){
					num = num * 10 + bd[j] - '0';
					if(num < inf) maxl = i; else{
						if(bl) n.insert(num);
						goto st;
					}
				}
				if(bl) n.insert(num);
				if(bd[j] != '*')
					goto st;
				maxl = j;
				i = j + 1;
				break;
			case '2':
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				if(j >= len){
					maxl = i; goto st;
				}
				maxl = j;
				for(; bd[j] >= '0' && bd[j] <= '9'; ++j){
					num = num * 10 + bd[j] - '0';
					if(num < inf) maxl = i; else{
						if(bl) n.insert(num);
						goto st;
					}
				}
				if(bl) n.insert(num);
				if(bd[j] != '*')
					goto st;
				maxl = j;
				i = j + 1;
				if(bd[i] < '1' || bd[i] > '3')
					goto st;
				maxl = i;
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				if(j >= len){
					maxl = i; goto st;
				}
				maxl = j;
				for(; bd[j] >= '0' && bd[j] <= '9'; ++j){
					num = num * 10 + bd[j] - '0';
					if(num < inf) maxl = i; else{
						if(bl) n.insert(num);
						goto st;
					}
				}
				if(bl) n.insert(num);
				if(bd[j] != '*')
					goto st;
				maxl = j;
				i = j + 1;
				break;
			case '1':
				num = 0; bl = bd[i + 1] == '#';
				if(!bl){
					maxl = i;
					goto st;
				}
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				if(j >= len){
					maxl = i; goto st;
				}
				maxl = j;
				for(; bd[j] >= '0' && bd[j] <= '9'; ++j){
					num = num * 10 + bd[j] - '0';
					if(num < inf) maxl = i; else{
						if(bl) n.insert(num);
						goto st;
					}
				}
				if(bl) n.insert(num);
				if(bd[j] != '*')
					goto st;
				maxl = j;
				i = j + 1;
				num = 0; bl = bd[i] == '#';
				j = i + (bd[i] == '#' ? 1 : 0);
				if(j >= len){
					maxl = i; goto st;
				}
				maxl = j;
				for(; bd[j] >= '0' && bd[j] <= '9'; ++j){
					num = num * 10 + bd[j] - '0';
					if(num < inf) maxl = i; else{
						if(bl) n.insert(num);
						goto st;
					}
				}
				if(bl) n.insert(num);
				if(bd[j] != '*')
					goto st;
				maxl = j;
				i = j + 1;
				if(bd[i] < '1' || bd[i] > '4')
					goto st;
				tmp = i;
				num = 0; bl = bd[i + 1] == '#';
				j = i + (bd[i + 1] == '#' ? 2 : 1);
				if(j >= len){
					maxl = i; goto st;
				}
				maxl = j;
				for(; bd[j] >= '0' && bd[j] <= '9'; ++j){
					num = num * 10 + bd[j] - '0';
					if(num < inf) maxl = i;
					if(num < inf) maxl = i; else{
						if(bl) n.insert(num);
						goto st;
					}
				}
				if(bl) n.insert(num);
				if(bd[tmp] == 4 && !num){
					maxl = tmp;
					goto st;
				}
				if(bd[j] != '*')
					goto st;
				maxl = j;
				i = j + 1;
				break;
			case '0':
				maxl = i++;
				if(m - S[fst] > 2) tt[S[fst]] = tt[m] = 1;
				fst--;
				break;
		}
	}
st:{}
	printf("%d\n", maxl + 1);
	printf("int main() {\n");
	for(set<int>::iterator it = n.begin(); it != n.end(); ++it)
		printf("    int r%d = 0;\n", *it);
	solve();
	printf("    printf(\"");
	set<int>::iterator it = n.begin();
	if(it != n.end()) printf("%%d"); it++;
	for(; it != n.end(); it++)
		printf(" %%d");
	printf("\"");
	for(it = n.begin(); it != n.end(); it++)
		printf(", r%d", *it);
	printf(");\n    return 0;\n}\n");
	return 0;
}

