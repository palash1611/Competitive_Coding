#include<bits/stdc++.h>
using namespace std;

class graph
{
public:
	int V;
	vector<int> *adj;

	graph(int v);
	void addEdge(int u, int v);
	void BFS(int s);

	void DFSutil(int v, bool visited[]);
	void DFS(int v);

	void DFS_iter(int v);
};


	this->V=v;
	adj=new vector<int>[v];
}

void graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
}

void graph::BFS(int s)
{
	bool visited[V]={false};

	queue <int> q;

	visited[s]=true;

	q.push(s);

	vector<int>::iterator i;

	while(!q.empty())
	{
		s=q.front();
		cout<<s<<" ";
		q.pop();

		for(i=adj[s].begin(); i!=adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
				q.push(*i);
			}
		}
	}
}


void graph::DFSutil(int v,bool visited[])
{
	visited[v]=true;
	cout<<v<<" ";

	vector<int>::iterator i;

	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			DFSutil(*i,visited);
		}
	}

}

void  graph::DFS(int v)
{
	bool visited[V]={false};

	DFSutil(v,visited);
}

void graph::DFS_iter(int v)
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
			cout<<v<<" ";
			visited[v]=true;
		}


		vector<int>::iterator i;

	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			s.push(*i);
		}
	}
	}
}


int main()
{

	 graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal "
         << "\n";
    g.BFS(2);
    cout<<endl;

    cout << "Depth First Traversal "
         << "\n";
    g.DFS(2);

    cout<<endl;

    cout << "Depth First Traversal iterative"
         << "\n";
    g.DFS_iter(2);



	return 0;
}
