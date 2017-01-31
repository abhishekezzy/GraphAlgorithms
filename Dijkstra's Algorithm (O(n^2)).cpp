#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
	int n,m,x,y,z,max=1000000000,u,min,pos;
	cin>>n>>m;
	int graph[n+1][n+1];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			graph[i][j]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		graph[x][y]=z;
		//graph[y][x]=z;
	}
	int dist[n+1], visited[n+1];
	for(int i=0;i<=n;i++)
	{
		dist[i]=max;
		visited[i]=0;
	}
	int src,dest;
	cin>>src>>dest;
	dist[src]=0;
	for(int i=0;i<=n;i++)
	{
		min=max;
		for(int i=0;i<=n;i++)
		{
			if(!visited[i]&&dist[i]<min)
			{
				min=dist[i];
				pos=i;
			}
		}
		u=pos;
		visited[u]=1;
		for(int i=0;i<=n;i++)
		{
			if(!visited[i] && graph[u][i]&& dist[u] + graph[u][i]<dist[i] && dist[u]!=max)
				dist[i]=dist[u]+graph[u][i];
		}
	}
	if(dist[dest]==max)
		cout<<"-1";
	else
		cout<<dist[dest];
}

