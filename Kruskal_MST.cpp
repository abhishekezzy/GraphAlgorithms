#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
class disjointSet
{
	public:
		
	    std::vector <int> parent, rank;
	    disjointSet(int n) 
		{
	        parent = std::vector <int> (n + 1);
	        rank = std::vector <int> (n + 1, 0);    
	        for(int i = 1; i <= n; i++)
	            parent[i] = i;
	    }
	    
	    //Path Compression heuristic
	    int find(int i)
		{
			if(i != parent[i])
				parent[i] = find(parent[i]);
			return parent[i];
			
			//without path compression
			/*while(i != parent[i])
				i = parent[i];
			return parent[i];*/
		}
	

		void union_byRank(int i, int j)
		{
			int i_id = find(i);
			int j_id = find(j);
			
			if(i_id == j_id)
				return;
		
			if(rank[i_id] > rank[j_id])
				parent[j_id] = i_id;
				
			else
			{
				parent[i_id] = j_id;
				if(rank[i_id] == rank[j_id])
					++rank[j_id];
			}
		}

};

int main()
{
	int n, m, mst = 0;
	std::cin >> n >> m;
	std::vector < std::pair <int, std::pair <int, int> > > v(m);
	disjointSet ds(n);
	
	for(int i = 0; i < m; i++)
	{
		int x, y, w;
		std::cin >> x >> y >> w;
		v.push_back(std::make_pair(w, std::make_pair(x,y)));
	}

	//sorting the edges in increasing order of their weights	
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		int x, y, w;
		w = v[i].first;
		x = v[i].second.first;
		y = v[i].second.second;	
		if(ds.find(x) != ds.find(y))
		{
			mst += w;  
			ds.union_byRank(x,y);
		}
	}
	
	std::cout << mst << std::endl;
}
