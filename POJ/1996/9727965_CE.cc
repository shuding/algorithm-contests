#include<ctdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX 210
const int INF = ~0U >> 1;
int n,m;
int map[MAX][MAX];

int max_flow(int num,int map[][MAX],int source,int sink)
{
    int q[MAX],first,end;
    int pre[MAX],min_flow[MAX];
    int flow[MAX][MAX];
    int ans=0;
    memset(flow,0,sizeof(flow));
    while(1)
    {
        first=0;
        end=0;
        q[end++]=source;
        memset(pre,-1,sizeof(pre));
        min_flow[source]=INF;
        pre[source]=-2;
        while(first<end)
        {
            int temp=q[first++];
            for(int i=0;i<num;i++)
            {
                if(pre[i]==-1&&flow[temp][i]<map[temp][i])
                {
                    q[end++]=i;
                    pre[i]=temp;
                    min_flow[i]=min(min_flow[temp],map[temp][i]-flow[temp][i]);
                }
            }
            if(pre[sink]!=-1)
            {
                int k=sink;
                while(pre[k]>=0)
                {
                    flow[pre[k]][k]+=min_flow[sink];
                    flow[k][pre[k]]=-flow[pre[k]][k];
                    k=pre[k];
                }
                break;
            }
        }
        if(pre[sink]==-1) return ans;
        else ans+=min_flow[sink];
    }
} 

int  main()
{
    int i,j;
    int a,b;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++) map[i][i+n]=1;
        for(i=0;i<m;i++)
        {
            scanf(" (%d,%d)",&a,&b);
            map[b+n][a]=map[a+n][b]=INF;
        }
        int ans=INF;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(j!=i)
                {
                    ans=min(max_flow(n*2,map,n+i,j),ans);
                }
            }
        }
        if(ans==INF) ans=n;
        printf("%d\n",ans);
    }
    return 0;
}