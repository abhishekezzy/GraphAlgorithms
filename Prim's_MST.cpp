#include <cmath>
#include<bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair< int, int > ipair;

int size = -1;
vector < ipair > h(10000);
map <int, int> pos;

//Implementation of Priority Queue
void swap(ipair  *a, ipair *b)
{
	ipair *temp;
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


void insert(int p, double w)
{
	//if(size == maxSize)
	//	return;
	size = size + 1;
	h[size] = make_pair(p, w);
	siftUp(size);
}

ipair extractMin()
{
	ipair p = make_pair(h[0].first, h[0].second);
	h[0] = h[size];
	size--;
	siftDown(0);
	return p;
}

/*void remove(int i)
{
	if(size == -1)
		cout << "Empty";
	h[i] = INT_MAX;
	siftUp(i);
	extractMax();
}*/

void changePriority(int i, double p)
{
	h[i].second = p;
	siftUp(i);	
}

int main() {
    int n, m, src, total_cost = 0;
    cin >> n >> m;
    vector < vector <ipair> > v(n+1);
    vector < ipair >::iterator it;
    
    for(int i = 0; i < m ; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    
    vector<int> dist(n + 1, INT_MAX);
    vector<int> visited(n + 1, 0);
    cin >> src;
    dist[src] = 0;
    
    for(int i = 1; i <= n; i++)
    	insert(i, dist[i]);
    
    while(size >= 0)
    {
    	ipair p = extractMin();
    	int u = p.first;
    	int cost = p.second;
    	total_cost += cost;
		visited[u] = 1;
		for(it = v[u].begin(); it != v[u].end(); ++it)
		{
			int v1 = (*it).first;
			int w = (*it).second;
			if( !visited[v1] && dist[v1] > w)
			{
				dist[v1] = w;
				changePriority(pos[v1], dist[v1]);
			}
		}
    }
    cout << total_cost << endl;
    return 0;
}

