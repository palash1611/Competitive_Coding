#include <bits/stdc++.h>
using namespace std;
#define V vector
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef V<int> vi;
typedef V<string> vs;
typedef V<LL> vll;
typedef V<double> vd;
typedef V<pii> vpii;
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)
#define fov(i,a) rep(i,(a).size())
#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define gi(x) scanf("%d",&x)
#define gl(x) cin >> x
#define gd(x) scanf("%lf",&x)
#define gs(x) cin >> x
#define pn printf("\n")
#define pi(x) printf("%d",x)
#define ppii(x) printf("%d %d ", x.fs, x.sc);
#define ppiin(x) ppii(x); pn;
#define pin(x) printf("%d\n",x)
#define pl(x) printf("%I64d",x)
#define pln(x) cout << x
#define ps(s) cout << s;
#define psn(s) cout << s << "\n"
#define spc printf(" ")
#define prec(x) cout<<fixed<<setprecision(x)
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define fr freopen("input.in", "r", stdin)
#define fw freopen("output.txt", "w", stdout)
#define SET(a, v) memset(a, v, sizeof a)
const int inf = numeric_limits<int>::max();
const LL linf = numeric_limits<LL>::max();
const double EPS = 1e-7;
const int maxn = 5005;
const int logmaxn = log2(maxn) + 3;
const int mod = (int)1e9 + 7;
int Abs(int X) {
	if (X >= 0) return X;
	return -X;
}
int main() {
	// fr;
	int T;
	char ch;
	gi(T);
	while (T--) {
		int N, K, res = 0;
		vi chor, police;
		gi(N); gi(K);
		rep(i, N)
    {
			chor.clear();
			police.clear();
			rep(j, N) 
      {
				cin >> ch;
				assert(ch == 'P' || ch == 'T');
				if (ch == 'P') police.pb(j);
				else chor.pb(j);
			}
			int l = 0, r = 0;
			while (l < chor.size() && r < police.size())
      {
				if (Abs(chor[l] - police[r]) <= K) {
					++res; ++l; ++r;
				} else if (chor[l] < police[r]) ++l;
				else ++r;
			}
		}
		pin(res);
	}
	return 0;
}
