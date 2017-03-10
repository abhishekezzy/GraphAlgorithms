#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int size = -1;
vector < pair <int,int> > h(1002);
int pos[1003] = {0};


void swap(pair <int, int> *a, pair <int, int> *b)
{
	pair <int, int> *temp;
	temp = a;
	a = b;
	b = temp;
}

int parent(int i)
{
	return i/2;
}

int leftChild(int i)
{
	return 2 * i;
}

int rightChild(int i)
{
	return 2 * i + 1;
}


void siftUp(int i)
{
	if (i == 0 || h[parent(i)].second < h[i].second)
	{
		pos[h[i].first] = i;
		return;
	}
	
	pos[h[parent(i)].first] = i; 
	pos[h[i].first] = parent(i);
	swap(h[i], h[parent(i)]);
	
	i = parent(i);
	siftUp(i);
}

void siftDown(int i)
{
	int maxIndex = i;
	int l = leftChild(i);
	int r = rightChild(i);
	
	if(l <= size && h[l].second < h[maxIndex].second)
		maxIndex = l;
		
	if(r <= size && h[r].second < h[maxIndex].second)
		maxIndex = r;
		
	if(i != maxIndex)
	{
		pos[h[maxIndex].first] = i;
		pos[h[i].first] = maxIndex;
		swap(h[i], h[maxIndex]);
	
		i = maxIndex;
		siftDown(i);
	}
	pos[h[i].first] = i;
}


void insert(int p, int w)
{
	//if(size == maxSize)
	//	return;
	size = size + 1;
	h[size] = make_pair(p, w);
	siftUp(size);
}

int extractMin()
{
	int result = h[0].first;
	h[0] = h[size];
	size--;
	siftDown(0);
	return result;
}

/*void remove(int i)
{
	if(size == -1)
		cout << "Empty";
	h[i] = INT_MAX;
	siftUp(i);
	extractMax();
}*/

void changePriority(int i, int p)
{
	h[i].second = p;
	siftUp(i);	
}

int main()
{
	int n, m, src, dst, u, v1, w;
	cin >> n >> m;
	vector < vector < pair <int, int> > > v(n+1);
	vector < pair <int, int> >:: iterator it;
	int dist[n+1], prev[n+1];
	
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v1 >> w;
		pair <int, int> p = make_pair(v1, w);
		v[u].push_back(p );
	}
	
	for(int i = 1; i <= n; i++)
	{
		dist[i] = INT_MAX;
		//prev[i] = -1;
	}
		
	cin >> src >> dst;
	dist[src] = 0;	
			
	//Making the Priority Queue
	for(int i = 1; i <= n; i++)
		insert(i,dist[i]);
	//cout << pos[src] << endl;
		
	for(int i = 0; i < n; i++)
	{
		//cout << pos[u] << " ";
		int u = extractMin();
		//cout << u << " " << pos[u] << endl;
		for(it = v[u].begin(); it != v[u].end(); ++it)
		{
			int v1 = (*it).first;
			//cout << v1 << endl;
			int w = (*it).second;
			//cout << v1 << " " << w << " "; 
			if(dist[u] != INT_MAX && dist[v1] > dist[u] + w)
			{
				dist[v1] = dist[u] + w;
				//cout << v1 << " " << pos[v1] << " " << h[pos[v1]].first << endl;
				//cout << dist[v1] << " " << pos[v1] << " " ;
				//prev[v1] = u;
				//cout << pos[v1] << " ";
				changePriority(pos[v1], dist[v1]);
				//cout << pos[v1] << endl;
			}
		}
	}
	if(dist[dst] == INT_MAX)
	 	cout << "-1" << endl;		
	else
		cout << dist[dst] << endl;
}

