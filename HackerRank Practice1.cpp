//
//
//
//https://www.hackerrank.com/challenges/greedy-florist/forum
//
#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int n, int k, vector < int > c){
    // Complete this function

    long minC=0;
    int flag=1;
    int a[n]={0};

    for(int i=0;i<(n/k)*k;i+=k)
    {
        for(int j=0;j<k;j++)
        {
            a[i+j]=flag;
        }
        flag++;
    }

    for(int i=(n/k)*k;i<n;i++)
    {
        a[i]=flag;
    }

    for(int i=0;i<n;i++)
    {
        minC+=c[i]*a[i];
    }

    return minC;

}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }

    //vector<int> newc(n);
    int temp;
    for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(c[i]<c[j])
			{
				temp  =c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}

    int minimumCost = getMinimumCost(n, k, c);
    cout << minimumCost << endl;
    return 0;
}
