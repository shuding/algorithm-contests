/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : game.cpp
*	Creation Time : 2013/01/14 21:58:59
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 1500
#define BASE 10000
using namespace std;

struct data{
	long long left, right, mul;
	bool operator < (const data &d) const{
		return mul < d.mul;
	}
	void init(){
		cin >> left >> right;
		mul = left * right;
	}
} d[MAXN];

struct number{
	int digit[5000];
	void init(long long n){
		if(n == 0){
			digit[0] = 1, digit[1] = digit[2] = 0;
			return;
		}
		while(n){
			digit[++digit[0]] = n % BASE;
			n /= BASE;
		}
		digit[digit[0] + 1] = 0;
	}
	bool operator < (const number &n) const{
		if(digit[0] < n.digit[0]) return 1;
		for(int i = digit[0]; i; --i)
			if(digit[i] < n.digit[i])
				return 1;
		return 0;
	}
	number operator * (long long n) const{
		number tmp;
		memcpy(tmp.digit, digit, sizeof digit);
		for(int i = 1; i <= tmp.digit[0]; ++i)
			tmp.digit[i] *= n;
		for(int i = 1; i <= tmp.digit[0]; ++i){
			tmp.digit[i + 1] += tmp.digit[i] / BASE;
			tmp.digit[i] %= BASE;
		}
		while(tmp.digit[tmp.digit[0] + 1])
			tmp.digit[0]++;
		return tmp;
	}
	number operator / (long long n) const{
		number tmp;
		memcpy(tmp.digit, digit, sizeof digit);
		long long mod = 0;
		for(int i = tmp.digit[0]; i; --i){
			tmp.digit[i] += mod * BASE;
			mod = tmp.digit[i] % n;
			tmp.digit[i] /= n;
		}
		while(tmp.digit[0] > 1 && !tmp.digit[tmp.digit[0]])
			--tmp.digit[0];
		return tmp;
	}
} ans, mul;

int n;

void calcAnswer(){
	ans.init(0);
	mul.init(d[0].left);
	for(int i = 1; i <= n; ++i){
		if((ans * d[i].right) < mul)
			ans = mul / d[i].right;
		mul = mul * d[i].left;
	}
}

int main(){
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i <= n; ++i)
		d[i].init();
	sort(d + 1, d + 1 + n);
	calcAnswer();
	printf("%d", ans.digit[ans.digit[0]]);
	for(int i = ans.digit[0] - 1; i; --i){
		if(ans.digit[i] < 1000) printf("0");
		if(ans.digit[i] < 100)  printf("0");
		if(ans.digit[i] < 10)   printf("0");
		printf("%d", ans.digit[i]);
	}
	printf("\n");
	return 0;
}
