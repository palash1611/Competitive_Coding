//https://practice.geeksforgeeks.org/problems/maximum-index/0
//https://articles.leetcode.com/a-distance-maximizing-problem/

/*
#include<bits/stdc++.h>
using namespace std;

#define V vector
typedef V <int> vi;
#define rep(i,n) for(int i=0;i<n;i++)
#define fov(i,a) for(int i=0;i<a.size();i++)
#define nl cout<<endl;
#define pb push_back

int main()
{
  int T;
  cin>>T;

  for(int k=0;k<T;k++)
  {
    int N;
    cin>>N;
    //cout<<"hello";nl;
    vector<int> arr;
    rep(i,N)
    {
      int temp;
      cin>>temp;
      arr.pb(temp);
    }

    int max=0;
    int temp;
    rep(i,N)
    {

      for(int j=i+1;j<N;j++)
      {
        if (arr[j]>=arr[i])
        temp=(j-i);

        if(temp>max)
        max=temp;
      }
    }

    cout<<max;nl;


  }


  return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int find(int *a,int n)
{
	int i=0,j=n-1;
	queue<pair<int ,int > > q;
	q.push(make_pair(i,j));
	map<pair<int ,int >,int  > mp;


	while(!q.empty())
	{
		int u = q.front().first;
		int v = q.front().second;
		q.pop();
		if(a[v]>a[u])
		{
			return v-u;
		}

		if(v-u>0)
		{
      //cout<<" "<<mp[make_pair(10,11)]<<endl;
			if(mp[make_pair(u+1,v)]==0)
			{
				mp[make_pair(u+1,v)]=1;
				q.push(make_pair(u+1,v));
			}
			if(mp[make_pair(u,v-1)]==0)
			{
				mp[make_pair(u,v-1)]=1;
				q.push(make_pair(u,v-1));
			}
		}
		else
		return 0;
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j;
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<find(a,n)<<"\n";
	}
}
