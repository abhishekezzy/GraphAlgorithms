#include<iostream>
using namespace std;
int abs(int x, int y) //returns absolute difference between two numbers
{
	if(x > y)
		return (x-y);
	else
		return (y-x);
}
int main()
{
	int t;
	cin>>t;
	for(int testcase=1;testcase<=t;testcase++)
	{
		int n;
		cin>>n;
		//For each wormholes, there shall be two Vertices
		//One Vertex for Wormhole entry and one for its exit and a bidirectional edge between them
		//2 extra vertices are for the Source and Destination
		int v = 2*n + 2 , e;
		int graph[v][v];
		//-1 denotes no edge between the vertices
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				graph[i][j]=-1;
		int xs,ys,xd,yd;
		cin>>xs>>ys>>xd>>yd;
		if(n==0)
			cout<<"#"<<testcase<<" "<<abs(xs,xd) + abs(ys,yd)<<endl;
		else
		{
			int a[n][5];
			e = abs(xs,xd) + abs(ys,yd);
			graph[0][v-1] = e;
			for(int i=0;i<n;i++)
					cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
			int k=1;
			//Constructing the main graph
			for(int i=0;i<n;i++)
			{
				graph[0][k] = abs(xs,a[i][0]) + abs(ys,a[i][1]); //edge b/w source and one point of wormhole	
				graph[0][k+1] = abs(xs,a[i][2]) + abs(ys,a[i][3]); //edge b/w source and the other point of wormhole
				graph[k][k+1] = a[i][4]; //edge between the 2 points of the wormhole
				graph[k+1][k] = a[i][4]; //edge between the 2 points of the wormhole 
				graph[k][v-1] = abs(xd,a[i][0]) + abs(yd,a[i][1]);
	 			graph[k+1][v-1] = abs(xd,a[i][2]) + abs(yd, a[i][3]);
	 			k = k + 2;
			}
			//For testing purpose
			/*for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
					cout<<graph[i][j]<<" ";
				cout<<endl;
			}*/
			//Connecting the points of wormholes with each other
			k=1;
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					int dist1 = abs(a[i][0],a[j][0]) + abs(a[i][1],a[j][1]);
					int dist2 = abs(a[i][0],a[j][2]) + abs(a[i][1],a[j][3]);
					int dist3 = abs(a[i][2],a[j][0]) + abs(a[i][3],a[j][1]);
					int dist4 = abs(a[i][2],a[j][2]) + abs(a[i][3],a[j][3]);
					graph[k][2*j + 1] = dist1;
					graph[2*j + 1][k] = dist1;
					graph[k][2*j + 2] = dist2;	
					graph[2*j+2][k] = dist2;
					graph[k+1][2*j + 1] = dist3;
					graph[2*j+1][k+1] = dist3;
					graph[k + 1][2*j + 2] = dist4;
					graph[2*j+2][k+1] = dist4;
				}
				k = k + 2;
			}
			//For Testing purpose
			/*for(int i=0;i<v;i++)
			{
				for(int j=0;j<v;j++)
					cout<<graph[i][j]<<" ";
				cout<<endl;
			}*/
			//Using Djikstra's Algorithm to find the shortest path from Source to Destination
			int max=100000000,min,pos,u;
			int visited[v],dist[v];
			for(int i=0;i<v;i++)
			{
				visited[i] = 0;
				dist[i] = max;
			}
			dist[0]=0;
			for(int i=0;i<v;i++)
			{
				min=max;
				for(int i=0;i<v;i++)
				{
					if(!visited[i]&&dist[i]<min)
					{
						min = dist[i];
						pos=i;
					}
				}
				u = pos;
				visited[u]=1;
				for(int i=0;i<v;i++)
				{
					if(!visited[i] &&graph[u][i]!=-1 && dist[u] + graph[u][i] < dist[i] && dist[u]!=max)
						dist[i] = dist[u] + graph[u][i];
				}
			}
			cout<<"#"<<testcase<<" "<<dist[v-1]<<endl;
		}
	}
}

