#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int> > mat,int src)
{
  int colorArr[V];
  for (int i = 0; i < V; ++i)
  colorArr[i] = -1;

  deque<int> q;
  colorArr[src]=1;
  q.push_back(src);
}

int main()
{
  int V,e;
  cin>>V>>e;
  vector<vector<int> > res(V);
  int i;
  for (i = 0 ; i < V ; i++ )
      res[i].resize(V);

  for(i = 0; i<n; i++)
  {
    for(j = 0; j<n; j++)
      {
        mat[i][j]=0;
      }
  }

  for(i=1;i<=e;i++)
	{
		cin>>u>>v;
		mat[u-1][v-1] = mat[v-1][u-1] = 1;
	}




  return 0;
}
