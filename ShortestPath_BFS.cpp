#include<bits/stdc++.h>
#include<limits.h>
#include<queue>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
int main()
{
	int n, m, u, V, x, y, max=1000000;
	cin>>n>>m;
	
	int dist[n+1];
	vector < vector <int>> v(n+1);
	vector <int>::iterator it;
	queue <int> q;
	
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		dist[i]=max;
	cin>>u>>V;
	dist[u]=0;
	q.push(u);
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		for(it=v[k].begin();it!=v[k].end();++it)
		{
			if(dist[*it]==max)
			{
				dist[*it]=dist[k]+1;
				q.push(*it);
			}
		}
	}
	if(dist[V]==max)
		cout<<"-1"<<endl;
	else
		cout<<dist[V];
}

