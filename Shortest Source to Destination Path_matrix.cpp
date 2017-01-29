#include<bits/stdc++.h>
#include<limits.h>
#define r(i,n) for(long long int i=0;i<n;i++)
using namespace std;
bool isValid(int r,int c, int n, int m)
{
	return( (r >= 0) && ( c >= 0 ) && ( r < n)  && ( c < m) );
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m, max=1000000, d1, d2, x, y, t1, t2;
		cin>>n>>m;
		int row[4]={0,1,0,-1};
		int col[4]={1,0,-1,0};
		int a[n][m];
		int dist[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		cin>>d1>>d2;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				dist[i][j]=max;
		queue <pair<int,int>> q;
		q.push(make_pair(0,0));
		dist[0][0]=0;
		if(a[0][0])
		{
			while(!q.empty())
			{
				x = q.front().first;
				y = q.front().second;
				q.pop();
				for(int i=0;i<4;i++)
				{
					t1 = x + row[i];
					t2 = y + col[i];
					if(isValid(t1,t2,n,m) && a[t1][t2] && dist[t1][t2]==max )
					{
						dist[t1][t2] = dist[x][y] + 1;
						q.push(make_pair(t1,t2));
					}
				}
			}
			if(dist[d1][d2]!=max)
				cout<<dist[d1][d2]<<endl;
			else
				cout<<"-1"<<endl;
		}
		else
			cout<<"-1"<<endl;
	}
}

