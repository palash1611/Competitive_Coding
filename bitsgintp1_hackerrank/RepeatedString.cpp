//https://www.hackerrank.com/contests/bitsgintp1/challenges/repeated-string
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
#define ll long long
#define rep(i,a) for(int i=0; i<(a); ++i)
#define fov(i,a) rep(i,(a).size())
#define nl cout<<endl;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair



// Complete the repeatedString function below.
long repeatedString(string s, long n) {
  long res=0;
  int size=s.length();
  int a=0;
  int t = n/size;
  //t=t*size;
  int rem = n-(t*size);
  //cout<<n<<" "<<size<<" "<<t<<" "<<rem;nl;
  for(char& c : s)
  {
    if (c=='a')
    a++;

  }

  res=a*t;
  //cout<<res;nl;

  for(char& c : s)
  {
    if(rem==0)
    break;
    if (c=='a')
    res++;
    rem--;
  }
  //cout<<res;nl;

  return res;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    cout << result << "\n";

  //  fout.close();

    return 0;
}
