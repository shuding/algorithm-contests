#include <stdio.h>  
#include <string.h>  
#include <algorithm>
#define Min(a, b) (a) < (b) ? a : b  
using  namespace std;  
const  int MAXN = 1005;  
const  int MAXM = 210000;  
const  int INF = 1000000000;  
struct  Edge  
{  
    int  st, ed;  
    int  next;  
    int  flow; 
    int cap; 
}edge[MAXM]; 
int  head[MAXN], level[MAXN], E, map[MAXN][MAXN];
void  add(int u, int v, int w)  
{  
    //printf("add %d %d %d\n", u, v, w);
    edge[E].flow = 0;  
    edge[E].cap = w;
    edge[E].st = u;  
    edge[E].ed = v;  
    edge[E].next = head[u];  
    head[u] = E++;      
    edge[E].flow = 0; 
    edge[E].cap = 0; 
    edge[E].st = v;  
    edge[E].ed = u;  
    edge[E].next = head[v];  
    head[v] = E++;  
}
int  dinic_bfs(int src, int dest, int ver)        
{        
    int i, j;         
    for (i = 0; i <= ver; i++)
    {    
        level[i] = -1;
    }
    int  que[MAXN], rear = 1;        
    que[0] = src; level[src] = 0;        
    for(i = 0; i < rear; i++) 
    {        
          for(j = head[que[i]]; j != -1; j = edge[j].next)
         {        
            if(level[edge[j].ed] == -1 && edge[j].cap > edge[j].flow)        
            {        
              level[edge[j].ed] = level[que[i]]+1;        
              que[rear++] = edge[j].ed;        
            }
         }
    }
    return  level[dest] >= 0;        
}        
     
int dinic_dfs(int src, int dest, int ver)        
{        
    int stk[MAXN], top = 0;        
    int ret = 0, cur, ptr, pre[MAXN], minf, i;        
    int del[MAXN];        
    for (i = 0; i <= ver; i++) 
    {
        del[i] = 0;
    }
    stk[top++] = src;         
    pre[src] = src; 
    cur = src;        
    while(top)        
    {        
        while(cur != dest && top)        
        {        
            for(i = head[cur]; i != -1; i = edge[i].next)        
            {        
                if(level[edge[i].ed] == level[cur] + 1 && edge[i].cap > edge[i].flow  && !del[edge[i].ed])        
                {        
                    stk[top++] = edge[i].ed;      
                    cur = edge[i].ed;        
                    pre[edge[i].ed] = i;                       
                    break;     
                }        
            }     
            if(i == -1)       
            {        
                del[cur] = 1;        
                top--;        
                if(top) cur = stk[top-1];        
            }        
        }                
        if(cur == dest)        
        {       
            minf = INF;        
            while(cur != src)        
            {        
                cur = pre[cur];        
                if(edge[cur].cap - edge[cur].flow < minf) minf = edge[cur].cap - edge[cur].flow;        
                cur = edge[cur].st;        
            }
            cur = dest;        
            while(cur != src)        
            {        
                cur = pre[cur];        
                edge[cur].flow += minf;        
                edge[cur^1].flow -= minf;        
                if(edge[cur].cap - edge[cur].flow == 0)
                {
                     ptr = edge[cur].st;
                }
                cur = edge[cur].st;        
            }        
            while(top > 0&& stk[top-1] != ptr) top--;        
            if(top)  cur = stk[top-1];        
            ret += minf;      
        }        
    }        
    return ret;        
}        
int Dinic(int src, int dest, int ver)        
{        
    int  ret = 0, t;        
    while(dinic_bfs(src, dest, ver))        
    {        
        t = dinic_dfs(src, dest, ver);        
        if(t) ret += t;        
        else  break;        
    }        
    return ret;        
}
void floyd(int n)//每个点的最近距离,这个不多说了。保证map[i][k]跟map[k][j]都以存在就行 
{
    int k, i, j;
    for (k = 1; k <= n; k++)//k表示中间点，一定放在最外面 
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            { 
                if (i != j && map[i][k] != INF && map[k][j] != INF && map[i][k] + map[k][j] < map[i][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}
void build(int distance, int k, int c, int m)
{
    int n = c + k, i, j;
    E = 0;
    for (i = 0; i <= n + 1; i++)
    {
        head[i] = -1;
    }
    for (i = k + 1; i <= n; i++) 
    {
        add(0, i, 1);//源到牛的容量是1 ，题目是要求每只牛都能去任意一个奶牛机就行了 
        for (j = 1; j <= k; j++)
        {
            if (map[i][j] <= distance)//对满足距离的两个点牛跟牛奶机 
            {
                add(i, j, INF);//牛到牛奶机的容量inf 
            }
        }
    }
    for (j = 1; j <= k; j++)//牛奶机到汇的容量为m 
    {
        add(j, n + 1, m);
    }
}
int main()
{
    int c, k, m, n, i, j;
    scanf("%d%d%d", &k, &c, &m);
    n = c + k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
            {
                map[i][j] = INF;
            }
        }    
    }
    floyd(n);
    int l = 0, r = INF - 10, mid, ans;
    int s = 0, t = c + k + 1, ver = t + 1;
    while (l < r)//因为二分出现l+1=r的时候，(l+r) >> 1 = l的。所以l+1就等于r了，当l跟r相等的时候就是解 
    {
        mid = (l + r) >> 1;
        build(mid, k, c, m);
        ans = Dinic(0, t, ver);
        if (ans == c)
        {
            r = mid;//r是保证能满足最大流等于牛的数量 
        }
        else
        {
            l = mid + 1; 
        }
    }
    printf("%d\n", r);
    return 0;
}