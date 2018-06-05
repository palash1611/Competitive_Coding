//BFS DFS withoout class
#include<bits/stdc++.h>
using namespace std;

int V;


void addEdge(vector<int> adj[], int u,int v)
{
  adj[u].push_back(v);
  //adj[v].push_back(u);
}

void BFS(vector<int> adj[], int v)
{
  bool visited[V]={false};

  queue<int> q;
  q.push(v);
  visited[v]=true;
  //cout<<v<<endl;
  while(!q.empty())
  {

    v=q.front();
    cout<<v<<" ";
    q.pop();

    for(int i=0;i<adj[v].size();i++)
    {
      if(!visited[adj[v][i]])
      {
        visited[adj[v][i]]=true;
      //  cout<<"-> "<<adj[v][i]<<endl;
        q.push(adj[v][i]);
      }
    }
  }

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
			cout<<v<<" ";
		}

		for(int i=0;i<adj[v].size();i++)
		{
			if(!visited[adj[v][i]])
			{
				s.push(adj[v][i]);
			}
		}
	}
}

void DFS_util(vector<int> adj[],int v,bool visited[])
{
	visited[v]=true;

	cout<<v<<" ";

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

}


int main()
{
  V=4;
  vector<int> adj[V];
//  cout<<"hello"<<endl;

  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,1,2);
  addEdge(adj,2,0);
  addEdge(adj,2,3);
  addEdge(adj,3,3);

  BFS(adj,2);
  cout<<endl;
  DFS(adj,2);
  cout<<endl;
  DFS_recur(adj,2);

  return 0;
}
