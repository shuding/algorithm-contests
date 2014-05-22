#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define INF 0x7FFFFFFF
#define gmax(a,b) ((a)>(b)?(a):(b))
#define gmin(a,b) ((a)<(b)?(a):(b))
#define fill(a,b) memset(a,b,sizeof(a))
#define MAXV 600000
#define MAXE 600000

using namespace std;

struct Edge{
    int ver;
    Edge *next;
    void SetData(int V, Edge *N){
        ver = V;
        next = N;
    }
};

Edge edgepool[MAXE << 1];
int edger;
Edge *onet[MAXV];
Edge *net[MAXV];
int dis[MAXV];
int Q[MAXV];
bool inQ[MAXV];
int w[MAXV];
int maxv;
int n, m;
int sccer;
int scc[MAXV];
int dfn[MAXV];
int low[MAXV];
int dfner;
int S[MAXV];
bool inS[MAXV];
bool g[MAXV];

void SPFA(int src){
    for (int i=1; i<maxv+1; i++){
        dis[i] = 0;
    }
    fill(inQ, 0);
    int head, tail;
    head = tail = 0;
    dis[src] = 0;
    if (++tail == maxv)
        tail = 0;
    Q[tail] = src;
    inQ[src] = 1;
    while (head != tail){
        if (++head == maxv)
            head = 0;
        int u = Q[head];
        inQ[u] = 0;
        for (Edge *e=net[u]; e; e=e->next){
            if (dis[e->ver] < dis[u] + w[e->ver]){
                dis[e->ver] = dis[u] + w[e->ver];
                if (!inQ[e->ver]){
                    if (++tail == maxv)
                        tail = 0;
                    Q[tail] = e->ver;
                    inQ[e->ver] = 1;
                    }
                }
            }
        }
}

void InsOEdge(int u, int v){
    edgepool[++edger].SetData(v, onet[u]);
    onet[u] = &edgepool[edger];
}

void InsEdge(int u, int v){
    edgepool[++edger].SetData(v, net[u]);
    net[u] = &edgepool[edger];
}

void DfsSCC(int u){
    dfn[u] = low[u] = ++dfner;
    S[++S[0]] = u;
    inS[u] = 1;
    for (Edge *e=onet[u]; e; e=e->next){
        if (!dfn[e->ver]){
            DfsSCC(e->ver);
            low[u] = gmin(low[u], low[e->ver]);
            }
        else
        if (inS[e->ver]){
            low[u] = gmin(low[u], dfn[e->ver]);
            }
        }
    if (low[u] == dfn[u]){
        sccer++;
        while (1){
            int t = S[S[0]--];
            inS[t] = 0;
            scc[t] = sccer;
            if (t == u)
                break;
            }
        }
}
    
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i;
    scanf("%d %d", &n, &m);
    while (m--){
        int u, v;
        scanf("%d %d", &u, &v);
        InsOEdge(u, v);
        }
    fill(dfn, 0);
    fill(scc, 0);
    dfner = sccer = 0;
    for (i=1; i<n+1; i++){
        if (!dfn[i])
            DfsSCC(i);
        }
    for (i=1; i<n+1; i++){
        for (Edge *e=onet[i]; e; e=e->next){
            if (scc[i] != scc[e->ver]){
                InsEdge(scc[i], scc[e->ver]);
                }
            }
        }
    maxv = sccer;
    for (i=1; i<n+1; i++){
        int t;
        scanf("%d", &t);
        w[scc[i]] += t;
        }
    int src;
    scanf("%d", &src);
    src = scc[src];
    SPFA(src);
    scanf("%d", &m);
    int ans = 0;
    while (m--){
        int t;
        scanf("%d", &t);
        t = scc[t];
        ans = gmax(ans, dis[t]);
        }
    ans += w[src];
    printf("%d\n", ans);
    return 0;
}

