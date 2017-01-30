#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int main()
{
	int n,m,x,y,k,p,check=0,c,flag=0;
	cin>>n>>m;
	vector < vector <int>> v(n+1);
	vector <int>:: iterator it;
	int color[n+1];
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);	
	}
	//set <int> U;
	//set <int> V;
	queue <int> q;
	//color[i]=0 represents WHITE color (unvisited vertex) for vertex i
	//color[i]=1 represents RED color (vertex belonging to set U) for vertex i
	//color[i]=2 represents BLUE color (vertex belonging to set V) for vertex i
	for(int i=1;i<=n;i++)
		color[i]=0;
	///BFS and Graph coloring to check whether Bipartite
	c=1;	
	for(int i=1;i<=n;i++)
	{
		if(color[i]==0)
		{
			c=1;
			q.push(i);
			color[i]=c;
			while(!q.empty())
			{
				flag=0;
				k=q.front();
				if(c==1)
					p=2;
				else if(c==2)
					p=1;
				q.pop();
				for(it=v[k].begin();it!=v[k].end();++it)
				{
					if(color[*it]==c)
					{
						check = 1;
						//cout<<*it<<" "<<c<<" "<<p<<endl;
						break;
					}
					else if(color[*it]==0)
					{
						q.push(*it);
						//flag=1;
						color[*it]=p;
					}	
				}
				if(check==1)
					break;
				if(!q.empty())
					c = color[q.front()];
			}
			if(check==1)
				break;
		}	
	}
	if(check)
		cout<<"0";
	else
		cout<<"1";
		
}

