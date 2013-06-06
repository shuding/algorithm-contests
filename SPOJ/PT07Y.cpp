#include <cstdio>
#include <vector>
using namespace std;
 
int n, m, a, b;
bool vst[10001];
vector<int> e[10001];
 
bool dfs(int v, int f){
	if(vst[v]) return 0;
	vst[v] = 1;
	bool ret = 1;
	for(vector<int>::iterator it = e[v].begin(); it != e[v].end(); ++it)
		if(*it != f)
			ret &= dfs(*it, v);
	return ret;
}
 
bool check(){
	scanf("%d%d", &n, &m);
	if(n != m + 1) return 0;
	while(m--){
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	bool ret = dfs(1, 0);
	for(; n; --n)
		ret &= vst[n];
	return ret;
}
 
int main(){
	puts(check() ? "YES" : "NO");
} 