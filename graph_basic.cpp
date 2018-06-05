#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > matMul(vector<vector<int> > mat, int k, int n)
{
  vector<vector<int> > res(n);
  for(int i=0;i<n;i++)
  res[i].resize(n);

  vector<vector<int> > mat2;


  mat2=mat;
  res=mat;

  for(int a=2;a<=k;a++)
    {
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          res[i][j]=0;
          for(int k=0;k<n;k++)
          {
            res[i][j]+=mat2[i][k]*mat[k][j];
          }
        }
      }
      mat2=res;
    }

    return res;
}

int main()
{
  int V,E;
  cin>>V>>E;

  vector<vector<int> >mat(V);
  for(int i=0;i<V;i++)
  mat[i].resize(V);

  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      mat[i][j]=0;
    }
  }

  for(int i=1;i<=E;i++)
  {
    int u,v;
    cin>>u>>v;
    mat[u-1][v-1] = mat[v-1][u-1] = 1;
  }

  int v,k;
  cin>>v>>k;

  vector<vector<int> > res(V);
  res=matMul(mat,k,V);

  for(int i=0;i<V;i++)
	{
		if(res[v-1][i]!=0)
		cout<<i+1<<" ";
	}

  return 0;
}

/*

#include<bits/stdc++.h>

using namespace std;


vector<vector<int> > matMul(vector<vector<int> > mat, int k, int n)
{
  //Declaring new 2D vector of size n
	vector<vector<int> > res(n);
	int i;
  //REsizing it to n x n
	for (i = 0 ; i < n ; i++ )
   		res[i].resize(n);

  //Multiplication k times
	int j,a;
	vector<vector<int> > mat2;
	mat2=mat;
	res=mat;
	for(a=2;a<=k;a++)
	{

	for (i = 0; i < n; i++)
    	{
        	for (j = 0; j < n; j++)
        	{
            		res[i][j] = 0;
            		for (k = 0; k < n; k++)
                	res[i][j] += mat2[i][k]*mat[k][j];
        	}
    	}

    	mat2 = res;
    	}
    	return res;


}


int main()
{
  //n= no of vertices , e = no of edges
	int n,e;
	cin>>n;
	cin>>e;
	int i,u,v,j;

  //Declaring new 2D vector of size n
	vector<vector<int> > mat(n);
  //REsizing it to n x n

	for (i = 0 ; i < n ; i++ )
   		mat[i].resize(n);
	//initializng matrix to 0
	for(i = 0; i<n; i++)
	{
    		for(j = 0; j<n; j++)
    		{

         		mat[i][j]=0;
    		}
	}

	//taking input of edges
	for(i=1;i<=e;i++)
	{
		cin>>u>>v;
		mat[u-1][v-1] = mat[v-1][u-1] = 1;
	}


	vector<vector<int> > res(n);

  //N= no of the vertex from where we have to find the vertices at a distance k
	int N,k;
	cin>>N>>k;

	res=matMul(mat, k, n);


	for(int i=0;i<n;i++)
	{
		if(res[N-1][i]!=0)
		cout<<i+1<<" ";
	}

	return 0;
}
*/
