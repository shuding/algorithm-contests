/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : vigenere.cpp
*	Creation Time : 2013/01/14 21:58:51
*	Environment   : OS X 10.8
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int lc, lk;
char c[2000], k[2000], m[2000];

char lower(char c){
	if(c >= 'A' && c <= 'Z')
		return char(c - 'A' + 'a');
	return c;
}

char handle(int p){
	int i, j = 0;
	for(i = lower(k[p]) - 'a'; i != lower(c[p]) - 'a'; i = (i + 1) % 26, ++j)
		;
	if(c[p] >= 'A' && c[p] <= 'Z')
		return char('A' + j);
	return char('a' + j);
}

void init(){
	cin >> k >> c;
	lk = strlen(k);
	lc = strlen(c);
	if(lc > lk){
		for(int i = lk; i < lc; ++i)
			k[i] = k[i - lk];
		k[lc] = '\0';
	}
}

void solve(){
	for(int i = 0; i < lc; ++i)
		m[i] = handle(i);
	m[lc] = '\0';
	cout << m << endl;
}

int main(){
	freopen("vigenere.in", "r", stdin);
	freopen("vigenere.out", "w", stdout);
	init();
	solve();
	return 0;
}
