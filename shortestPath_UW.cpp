#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int > adj[],int src,int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}


bool BFS(vector<int> adj[],int src,int dest,int v, int pred[],int dist[])
{
  queue<int> q;
  bool visited[v]={false};

  for(int i=0;i<v;i++)
  {
    pred[i]=-1;
    dist[i]=INT_MAX;
  }

  visited[src]=true;
  q.push(src);
  dist[src]=0;

  while(!q.empty())
  {
    int u = q.front();
    q.pop();

    for(int i=0;i<adj[u].size();i++)
    {
      if(!visited[adj[u][i]])
      {
        visited[adj[u][i]]=true;
        dist[adj[u][i]]=dist[u]+1;
        pred[adj[u][i]]=u;

        q.push(adj[u][i]);

        if(adj[u][i]==dest)
        return true;
      }
    }

  }

  return false;
}


int main()
{


  return 0;
}
