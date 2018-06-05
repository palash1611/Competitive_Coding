#include<bits/stdc++.h>
using namespace std;
int V;
void addEdge(vector<pair<int,int> > adj[],int u,int v, int wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}
void djk(vector<pair<int,int> > adj[],int dist[],int src)
{
	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	priority_queue<pair<int,int>, vector<pair<int,int> >,greater< pair<int,int> > > pq;
	pq.push(make_pair(0,src));
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			if(dist[adj[u][i].first] > (dist[u] + adj[u][i].second))
			{
				dist[adj[u][i].first] = dist[u] + adj[u][i].second;
				pq.push(make_pair(dist[adj[u][i].first],adj[u][i].first));
			}
		}
	}
}
int main()
{
	cin>>V;
	vector<pair<int,int> > adj[V];
	int dist[V];
	addEdge(adj,0, 1, 4);
    addEdge(adj,0, 7, 8);
    addEdge(adj,1, 2, 8);
    addEdge(adj,1, 7, 11);
    addEdge(adj,2, 3, 7);
    addEdge(adj,2, 8, 2);
    addEdge(adj,2, 5, 4);
    addEdge(adj,3, 4, 9);
    addEdge(adj,3, 5, 14);
    addEdge(adj,4, 5, 10);
    addEdge(adj,5, 6, 2);
    addEdge(adj,6, 7, 1);
    addEdge(adj,6, 8, 6);
    addEdge(adj,7, 8, 7);
    djk(adj,dist,0);
    for(int i=0;i<V;i++)
    {
    	cout<<i<<" "<<dist[i]<<endl;
    }
}
