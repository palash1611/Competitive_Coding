//Prims
#include<bits/stdc++.h>
using namespace std;
int V;
void addEdge(vector<pair<int,int> > adj[],int u,int v, int wt)
{
	adj[u].push_back(make_pair(v,wt));
	adj[v].push_back(make_pair(u,wt));
}
int minKey(int key[],bool mstSet[])
{

	int min = INT_MAX, min_index;
	for(int v=0;v<V;v++)
	{
		if(mstSet[v]==false && key[v] < min)
		{
			min=key[v];
			min_index=v;
		}
    }
    return min_index;
}
int printMST(int parent[],vector<pair<int,int> > adj[])
{
	for(int i=1;i<V;i++)
	{
		for(int j=0;j<adj[parent[i]].size();j++)
        {
        	if(adj[parent[i]][j].first==(i))
        	{
        	    cout<<parent[i]<<" "<<(i)<<" "<<adj[parent[i]][j].second;
	            cout<<endl;
        	}
        }

    }
}
void primMST(vector<pair<int,int> > adj[])
{
	int parent[V];
	int key[V];
	bool mstSet[V];
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(int cnt=0;cnt<(V-1);cnt++)
	{
		int u=minKey(key,mstSet);
		mstSet[u]=true;
		for(int v=0;v<adj[u].size();v++)
		{
			if(mstSet[adj[u][v].first]==false && adj[u][v].second<key[adj[u][v].first])
			{
				parent[adj[u][v].first]=u;
				key[adj[u][v].first]=adj[u][v].second;
			}

		}
	}
	printMST(parent,adj);
}
void printGraph(vector<pair<int,int> > adj[])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			cout<<i<<" "<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
		}

	}
}
int main()
{
	cin>>V;
	vector<pair<int,int> > adj[V];
	addEdge(adj,0,1,2);
	addEdge(adj,0,3,6);
	addEdge(adj,1,2,3);
	addEdge(adj,1,3,8);
	addEdge(adj,1,4,5);
	addEdge(adj,2,4,7);
	addEdge(adj,3,4,9);
//	printGraph(adj);
	primMST(adj);
	return 0;
}
