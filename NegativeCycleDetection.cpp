#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int main()
{
	long long int n, m, flag = 0, max = 100000000000000;
	cin >> n >> m;
	vector < vector <long long int> > v(m); 
	vector < vector <long long int> > vtemp(n + 1); 
	vector <long long int>::iterator it;
	for(long long int i = 0; i < m; i++)
	{
		long long int x, y, z;
		cin >> x >> y >> z;
		v[i].push_back(x);
		v[i].push_back(y);
		v[i].push_back(z);
		vtemp[x].push_back(y);
	}
	int visited[n + 1];
	for(long long int i = 1; i<= n; i++)
		visited[i] = 0;
		
	long long int dist[n + 1];
	for(long long int i = 1; i<= n; i++)
		dist[i] = max;
		
	stack <int> s2;
	stack <int> s1;
	for(int i = 1;i <= n; i++)
	{
		if(visited[i]==0)
		{
			s1.push(i);
			visited[i]=1;
			while(!s1.empty())
			{
				flag = 0;
				int k = s1.top();
				for(it = vtemp[k].begin(); it != vtemp[k].end(); ++it)
				{
					if(visited[*it] == 0)
					{
						s1.push(*it);
						visited[*it] = 1;	
						flag = 1;
						break;
					}
				}
				//Reverse order processing (Topological Sort trick)
				if(flag == 0)
				{
					s2.push(k);
					s1.pop();	
				}
			}	
		}
	}	
	dist[s2.top()] = 0;	
	
	flag = 0;
	//for(int i = 1; i <= n; i++)
	//	cout << dist[i]<<" ";	
	for(long long int j = 1; j <= n-1; j++)
	{
		for(long long int i = 0; i < m; i++)
		{
			long long int u1 = v[i][0];
			long long int v1 = v[i][1];
			long long int w1 = v[i][2];
			if( dist[u1] + w1 < dist[v1])
				dist[v1] = dist[u1] + w1;
		}
	}
	//for(int i = 1; i <= n; i++)
	//	cout << dist[i]<<" ";
	//cout<<endl;
	for(long long int i = 0; i < m; i++)
	{
		long long int u1 = v[i][0];
		long long int v1 = v[i][1];
		long long int w1 = v[i][2];
		if( dist[u1] + w1 < dist[v1])
		{
			flag = 1;
			break;
		}
	}
	//for(int i = 1; i <= n; i++)
	//	cout << dist[i]<<" ";
//	cout<<endl;
	if(flag == 1)
		cout <<"1" <<endl;
	else
		cout <<"0"<<endl;	
}

