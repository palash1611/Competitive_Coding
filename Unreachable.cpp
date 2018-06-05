#include<bits/stdc++.h>
using namespace std;

int V,M;


void addEdge(vector<int> adj[], int u,int v)
{
  adj[u].push_back(v);
  //adj[v].push_back(u);
}



void DFS(vector<int> adj[],int v)
{

	vector<bool> visited(V,false);

	stack<int> s;

	s.push(v);

	while(!s.empty())
	{
		v=s.top();

		s.pop();

		if(!visited[v])
		{
			visited[v]=true;
			//cout<<v<<" ";
		}

		for(int i=0;i<adj[v].size();i++)
		{
			if(!visited[adj[v][i]])
			{
				s.push(adj[v][i]);
			}
		}
	}


	int count=0;
//	cout<<endl;
	for(int i=0;i<V;i++)
	{
	    if(visited[i]==false)
	    count++;
	}

	cout<<count;
}

void DFS_util(vector<int> adj[],int v,bool visited[])
{
	visited[v]=true;

	//cout<<v<<" ";

	for(int i=0;i<adj[v].size();i++)
	{
		if(!visited[adj[v][i]])
		{
			DFS_util(adj,adj[v][i],visited);
		}
	}

}

void DFS_recur(vector<int> adj[],int v)
{
	bool visited[v]={false};

	DFS_util(adj,v,visited);

  int count=0;
//	cout<<endl;
	for(int i=0;i<V;i++)
	{
	    if(visited[i]==false)
	    count++;
	}

	cout<<count;
}

int main()
{

    cin>>V>>M;
    int u,v;
    vector<int> adj[V];

    for(int i=0;i<M;i++)
    {

        cin>>u>>v;
        addEdge(adj,u-1,v-1);
    }
    int head;
    cin>>head;

    DFS_recur(adj,head-1);
}
