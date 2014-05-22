#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int,int> > dice;
vector<bool> used;
int n;
int edge[7][7];
int degree[7];
bool visited[7] = {false};
int circuit[500] = {0};
int pos = 0;
void dfs(int num)
{
    visited[num] = true;
    for (int i=0;i<7;i++)
    {
        if (!visited[i] && edge[num][i]>0)
            dfs(i);
    }
}
int getStart()
{
    int cnt = 0;
    for (int i=0;i<7;i++)
        if (degree[i] % 2)  cnt ++;
    if (cnt==2) 
    {
        for (int i=0;i<7;i++)
            if (degree[i] % 2)  return i;
    }
    else if (cnt == 0)
    {
        for (int i=0;i<7;i++)
            if (degree[i] > 0)   return i;
    }
    return -1;
}
 
void EulerTour(int num)
{
    for (int i=0; i<7; i++)
        if (edge[num][i])
        {
            edge[num][i] -- ;
            edge[i][num] --;
            EulerTour(i);
        }
    circuit[pos++] = num;
}
bool getAC()
{
    for (int i=0;i<7;i++)
        if (degree[i] > 0)   {   dfs(i); break;  }
    for (int i=0;i<7;i++)
        if (degree[i]>0 && !visited[i])  return false;
    int startNode = getStart();
    if (startNode == -1)    return false;
    EulerTour(startNode);
    return true;
}
int main()
{
    memset(edge,0,sizeof(edge));
    scanf("%d",&n);
    int a,b;
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        dice.push_back(make_pair(a,b));
        used.push_back(false);
        edge[a][b] ++ ; edge[b][a] ++;
        degree[a]++ ;degree[b]++;
    }
    if (!getAC())   printf("No solution\n");
    else
    {
        for (int i=pos-1;i>0;i--)
            for (int j=0;j<dice.size();j++)
                if (!used[j])
                {
                    if (dice[j].first==circuit[i] && dice[j].second==circuit[i-1])
                    {
                        printf("%d %c\n",j+1,'+');
                        used[j] = true;
                        break;
                    }
                    else if (dice[j].second==circuit[i] && dice[j].first==circuit[i-1])
                    {
                        printf("%d %c\n",j+1,'-');
                        used[j] = true;
                        break;
                    }
                }
    }
    return 0;
}

