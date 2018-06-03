//https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/joker-and-thieves-53e59f4a/description/
#include<bits/stdc++.h>
using namespace std;
#define V vector
typedef V<int> vi;
#define inp(x) cin>>x
#define loop(i,n) for(int i=0;i<n;i++)
#define pb push_back
int main()
{
  int T;
  char ch;
  inp(T);
  int res=0;
  while(T--)
  {
    res=0;
    int N,K;
    vi chor,police;
    inp(N);inp(K);
    loop(i,N)
    {
      int x=0;
      chor.clear();
      police.clear();
      loop(j,N)
      {
        inp(ch);
        if(ch=='P')
        police.pb(j);
        else
        chor.pb(j);
      }

      /*  for(int g=0;g<police.size();g++)
        cout<<police[g]<<" ";
        cout<<endl;

        for(int g=0;g<chor.size();g++)
        cout<<chor[g]<<" ";
        cout<<endl;*/

        int l=0,r=0;
        while(l<chor.size() && r<police.size())
        {
          if(abs(chor[l]-police[r])<=K)
            {
            //  cout<<chor[l]<<" "<<police[r]<<" ";
              l++;r++;x++;
            }
          else if(chor[l]<police[r]) l++;
          else r++;
        }
      //  cout<<x<<endl;
        res+=x;
    }

    cout<<res<<endl;
  }



  return 0;
}

//Alternate SOl
/*


    #include <bits/stdc++.h>
    #define pb push_back
    #define mp make_pair
    #define MAX 5123
    #define NIL 0
    #define INF (1<<28)
    using namespace std;
    char a[51][51];
    int police[51][51];
    int thief[51][51];
    vector< int > G[MAX];
    int n, m, match[MAX], dist[MAX];
    // n: number of nodes on left side, nodes are numbered 1 to n
    // m: number of nodes on right side, nodes are numbered n+1 to n+m
    // G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]
    bool bfs() {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++) {
            if(match[i]==NIL) {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[NIL] = INF;
        while(!Q.empty()) {
            u = Q.front(); Q.pop();
            if(u!=NIL) {
                len = G[u].size();
                for(i=0; i<len; i++) {
                    v = G[u][i];
                    if(dist[match[v]]==INF) {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[NIL]!=INF);
    }
    bool dfs(int u) {
        int i, v, len;
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==dist[u]+1) {
                    if(dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    int hopcroft_karp() {
        int matching = 0, i;
        while(bfs())
            for(i=1; i<=n; i++)
                if(match[i]==NIL && dfs(i))
                    matching++;
        return matching;
    }
    void solve() {
    	for(int i=0;i<MAX;i++) G[i].clear();
    	memset(match,0,sizeof(match));
    	memset(dist,0,sizeof(dist));

    	int N, K;
    	cin>>N>>K;
    	assert(N>=1 && N<=50);
    	assert(K>=1 && K<=N);
    	int cnt_p = 0, cnt_t = 0;
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			cin>>a[i][j];
    			assert(a[i][j]=='P' || a[i][j]=='T');
    		}
    	}

    	for(int i=0;i<N;i++)
    		for(int j=0;j<N;j++)
    			if(a[i][j] == 'P') {
    				cnt_p++;
    				police[i][j] = cnt_p;
    			}
    			else {
    				cnt_t++;
    				thief[i][j] = cnt_t;
    			}
    	n = cnt_p, m = cnt_t;
    	int pol,thf;

    	for(int i=0;i<N;i++) {
    		for(int j=0;j<N;j++) {
    			if(a[i][j]=='P') {
    				pol=police[i][j];
    				for(int k=0;k<N;k++) {
    					if(abs(k-j) <= K && a[i][k] == 'T' && k!=j) {
    						thf=thief[i][k];
    						G[pol].pb(cnt_p + thf);
    					}
    				}
    			}
    		}
    	}

    	int ans = hopcroft_karp();
    	cout << ans << "\n";
    }
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	int t;cin>>t;
    	assert(t>=1 && t<=10);
    	while(t--) solve();
    }

*/
