#include<bits/stdc++.h>
using namespace std;
int V;
void addEdge(vector<pair<int,int> > adj[],int u,int v,int wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}
void zeroOneBFS(vector<pair<int,int> > adj[],int v)
{
	int dist[V];
	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
	}
	deque<int> q;
	dist[v]=0;
	q.push_front(v);
	while(!q.empty())
	{
		v=q.front();
		q.pop_front();
		for(int i=0;i<adj[v].size();i++)
		{
			if(dist[adj[v][i].first] > dist[v] + adj[v][i].second)
			{
				dist[adj[v][i].first] = dist[v] + adj[v][i].second;
        if(adj[v][i].second==0)
				q.push_front(adj[v][i].first);
        else
        q.push_back(adj[v][i].first);
      }
		}
	}
	for (int i=0; i<V; i++)
        cout << dist[i] <<" ";
}
int main()
{
	cin>>V;
	vector<pair<int,int> > adj[V];
    addEdge(adj,0, 1, 0);
    addEdge(adj,0, 7, 1);
    addEdge(adj,1, 7, 1);
    addEdge(adj,1, 2, 1);
    addEdge(adj,2, 3, 0);
    addEdge(adj,2, 5, 0);
    addEdge(adj,2, 8, 1);
    addEdge(adj,3, 4, 1);
    addEdge(adj,3, 5, 1);
    addEdge(adj,4, 5, 1);
    addEdge(adj,5, 6, 1);
    addEdge(adj,6, 7, 1);
    addEdge(adj,7, 8, 1);
    int v = 0;//source node
    zeroOneBFS(adj,v);
    return 0;
}
