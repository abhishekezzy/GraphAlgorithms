#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
typedef pair<int, int> iPair;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, src, dst, u, v1, w;
		cin >> n >> m;
		vector < vector < iPair > > v(n+1);
		vector < iPair >:: iterator it;
		vector<int> dist(n+1, INT_MAX);
        vector<int> visited(n+1, 0);
		priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
		
		for(int i = 0; i < m; i++)
		{
			cin >> u >> v1 >> w;
			iPair p1 = make_pair(v1, w);
            iPair p2 = make_pair(u, w);
			v[u].push_back(p1);
            v[v1].push_back(p2);
		}
	
		cin >> src;
		dist[src] = 0;
		pq.push(make_pair(0, src));
		
		while(!pq.empty())
		{
			int u = pq.top().second;
            visited[u] = 1;
			pq.pop();
			for(it = v[u].begin(); it != v[u].end(); ++it)
			{
				int v1 = (*it).first;
	            int weight = (*it).second;
	 
	            //  If there is shorter path to v through u.
	            if (!visited[v1] && dist[u] != INT_MAX && dist[v1] > dist[u] + weight)
	            {
	                // Updating distance of v
	                dist[v1] = dist[u] + weight;
	                pq.push(make_pair(dist[v1], v1));
	            }
			}
		}
		
		for(int i = 1; i <= n; i++)
		{
			if(i == src)
				continue;
			else if(dist[i] == INT_MAX)
				cout << "-1 " ;
			else
				cout << dist[i] << " ";
		}
		cout << endl;
	}
}

			
