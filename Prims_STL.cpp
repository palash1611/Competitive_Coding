#include<bits/stdc++.h>
using namespace std;

typedef pair<int , int > ipair;

void addEdge(int u,int v,int w,vector<ipair> vec[])
{
  vec[u].push_back(make_pair(v,w));
  vec[v].push_back(make_pair(u,w));
}

void prim(int n,vector<ipair > vec[])
{
  priority_queue<ipair,vector< ipair >,greater< ipair> > pq;
  int src=0;
  vector< int > key(n,100000);
  vector<int > parent(n,-1);
  vector<bool > ismst(n,false);
  pq.push(make_pair(0,src));
  key[src]=0;
  while(!pq.empty())
  {
    int x=pq.top().second;
    //int w=pq.top().first;
    ismst[x]=true;
    pq.pop();
    for(int i=0;i<vec[x].size();i++)
    {
        int v=vec[x][i].first;
        int w=vec[x][i].second;
        if(ismst[v]==false&&key[v]>+w)
        {
          key[v]=w;
          pq.push(make_pair(key[v],v));
          parent[v]=x;
        }
    }
  }
  for (int i = 1; i < n; ++i)
       printf("%d - %d\n", parent[i], i);

}
int main ()
{
  int n;
  cin>>n;
  vector<ipair> v[n];
  addEdge(0, 1, 4,v);
  addEdge(0, 7, 8,v);
    addEdge(1, 2, 8,v);
    addEdge(1, 7, 11,v);
    addEdge(2, 3, 7,v);
    addEdge(2, 8, 2,v);
    addEdge(2, 5, 4,v);
    addEdge(3, 4, 9,v);
    addEdge(3, 5, 14,v);
    addEdge(4, 5, 10,v);
    addEdge(5, 6, 2,v);
    addEdge(6, 7, 1,v);
    addEdge(6, 8, 6,v);
    addEdge(7, 8, 7,v);

    prim(n,v);

    return 0;

}
