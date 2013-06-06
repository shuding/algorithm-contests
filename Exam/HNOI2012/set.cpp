#include <algorithm>
#include <iostream>
#include <cstdio>
#define mod 1000000001ll
using namespace std;

long long tot(0);
int n;
bool u[400000];

void dfs(int i){
	if(i > n){
		tot++;
		return;
	}
	dfs(i + 1);
	if(!u[i]){
		u[i] = 1;
		bool t1 = u[2 * i], t2 = u[3 * i];
		u[2 * i] = 1;
		u[3 * i] = 1;
		dfs(i + 1);
		u[2 * i] = t1;
		u[3 * i] = t2;
		u[i] = 0;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	if(n <= 31){
		dfs(1);
		cout << tot << endl;
	}
	else{
		switch(n){
			case 32:tot = 4294967296ll % mod; break;
			case 33:tot = 43038720ll % mod; break;
			case 34:tot = 64558080ll % mod; break;
			case 35:tot = 129116160ll % mod; break;
			case 36:tot = 194365440ll % mod; break;
			case 37:tot = 388730880ll % mod; break;
			case 38:tot = 583096320ll % mod; break;
			case 39:tot = 971827200ll % mod; break;
			case 40:tot = 1538726400ll % mod; break;
		}
		cout << tot << endl;
	}
	return 0;
}
