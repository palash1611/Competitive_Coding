//https://practice.geeksforgeeks.org/problems/finding-the-numbers/0
/*You are given an array A containing 2*N+2 positive numbers,
out of which N numbers are repeated exactly once and the other two
numbers occur exactly once and are distinct. You need to find the other
two numbers and print them in ascending order.*/

#include<bits/stdc++.h>


using namespace std;
int main()
 {
	//code
	int test;
	cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int k = (2*n)+2;
        int arr[k];
        for(int i=0;i<k;i++)
        cin>>arr[i];
        sort(arr,arr+k);
        int i=0;
        while(i<k)
        {
            if(arr[i]!=arr[i+1])
            {
                cout<<arr[i]<<" ";
                i++;
            }
            else
            i=i+2;
        }
        cout<<endl;
    }
	return 0;
}

/*
int main() {
	vector <long> v;
	int n , t , a;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < (2*n)+2 ; ++i)
			cin >> a , v.push_back(a);

		sort (v.begin() , v.end());
		vector <long> v2;

		for (int i = 0; i < (2*n)+2 ; ++i)
		{
			if (!i and v[i] != v[i+1]) v2.push_back(v[i]);
					else if (i == 2*n+1 and v[i] != v[i-1]) v2.push_back(v[i]);
							else if (v[i] != v[i+1] and v[i] != v[i-1]) v2.push_back(v[i]);
		}

		for (int i = 0 ; i < v2.size() ; ++i)
			cout << v2[i] << " ";

		cout << endl;
		v.clear();
		v2.clear();
	}
}*/
