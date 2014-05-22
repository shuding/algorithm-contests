#include <cstdio>
int n, m, a, b, fa[200010];
long long ans = 1;
int father(int v){
	return fa[v] == v ? v : fa[v] = father(fa[v]);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
	while(m--){
		scanf("%d%d", &a, &b);
	if(father(a) == father(b))
			ans <<= 1;
		fa[father(a)] = father(b);
		printf("%lld\n", ans - 1);
	}
	return 0;
}
