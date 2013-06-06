#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX 1<<25
using namespace std;

int k,c,m;
int a[540][540];
bool b[540][540];
bool v[1000];
int fa[1000];

void init()
{
     int i,j;
     scanf("%d%d%d",&k,&c,&m); 
     for (i=1;i<=k+c;i++)
      for (j=1;j<=k+c;j++) 
      {
          scanf("%d",&a[i][j]);
          if (a[i][j]==0) a[i][j]=MAX;
      }
}
     
void floyd()
{
     int l,i,j;
     for (l=1;l<=k+c;l++)
       for (i=1;i<=k+c;i++)  if (a[i][l]!=MAX && i!=l)
         for (j=1;j<=k+c;j++) if (a[l][j]!=MAX && j!=l && i!=j)
          if (a[i][l]+a[l][j]<a[i][j])  
               a[i][j]=a[i][l]+a[l][j];
}

bool dfs(int x)
{
     int i,y;
     if (x%m==0) y=x/m; else y=x/m+1;
     for (i=1;i<=c;i++)
      if (b[y][i] && !v[i])
      {
          v[i]=true;
          if ( fa[i]==0 || dfs(fa[i]) )
          {
            fa[i]=x; return true;
          }
      }
      return false;
}

int main()
{
   int l,r,mid,now,ans;
   int i,j;
   
   init();
   floyd();
   l=0; r=1001; ans=0;
   while (l<=r)
   {
         memset(b,0,sizeof(b));
         mid=(l+r)>>1;
         for (i=1;i<=k;i++)
          for (j=k+1;j<=k+c;j++)
           if (a[i][j]<=mid) b[i][j-k]=true;
         now=0;
         memset(fa,0,sizeof(fa));
         for (i=1;i<=k*m;i++)
         {
             memset(v,0,sizeof(v));
             if (dfs(i)) now++;
             if (now==c) break;
         }
         if (now==c) r=mid-1,ans=mid;
         else l=mid+1;
   }
   printf("%d\n",ans);
   return 0;
}