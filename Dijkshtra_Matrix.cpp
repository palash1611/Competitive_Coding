#include<bits/stdc++.h>
using namespace std;
#define loop(x,n) for(int x = 0; x < n; x++)
int V;

int minDistance(int dist[], bool set[])
{
  int min_index,min=INT_MAX;
  for(int i=0;i<V;i++)
  {
    if(set[i]==false && dist[i]<=min)
    min=dist[i], min_index=i;
  }
  return min_index;
}

int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d -> %d\n", i, dist[i]);
}

void dijkshtra(vector<vector<int> > adj, int src)
{
//  cout<<"HELLO";
  int dist[V];
  bool set[V];
  loop(i,V)
  {
    dist[i]=INT_MAX;
    set[i]=false;
  }
  dist[src]=0;

  for(int i=0;i<V-1;i++)
  {
    int u=minDistance(dist,set);
    set[u]=true;

    for(int v=0;v<V;v++)
    {
    if(!set[v] && adj[u][v] && dist[u] != INT_MAX
                                       && dist[u]+adj[u][v] < dist[v])
      {
        dist[v]=dist[u] + adj[u][v];
      }
    }
  }
  printSolution(dist,V);
}

int main()
{
  V=9;
  vector<vector<int> > adj(V);

  for(int i=0;i<V;i++)
  adj[i].resize(V);

  adj={{0, 4, 0, 0, 0, 0, 0, 8, 0},
       {4, 0, 8, 0, 0, 0, 0, 11, 0},
       {0, 8, 0, 7, 0, 4, 0, 0, 2},
       {0, 0, 7, 0, 9, 14, 0, 0, 0},
       {0, 0, 0, 9, 0, 10, 0, 0, 0},
       {0, 0, 4, 14, 10, 0, 2, 0, 0},
       {0, 0, 0, 0, 0, 2, 0, 1, 6},
       {8, 11, 0, 0, 0, 0, 1, 0, 7},
       {0, 0, 2, 0, 0, 0, 6, 7, 0} };

    /*   loop(i,V)
       {
         loop(j,V)
         {
           cout<<adj[i][j]<<" ";
         }
         cout<<endl;
       }*/

       dijkshtra(adj,0);


  return 0;
}
