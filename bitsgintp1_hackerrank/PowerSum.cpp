//https://www.hackerrank.com/contests/bitsgintp1/challenges/the-power-sum/problem
#include <bits/stdc++.h>


using namespace std;

// Complete the powerSum function below.
int powerSum(int X, int N,int k) {
  if(X==0 ) return 1;
  if(X<0 || pow(k,N)>X) return 0;

    return powerSum(X-pow(k,N),N,k+1)+powerSum(X,N,k+1);

}

int main()
{


    int X;
    cin >> X;


    int N;
    cin >> N;


    int result = powerSum(X, N,0)/2;

    cout << result << "\n";



    return 0;
}
