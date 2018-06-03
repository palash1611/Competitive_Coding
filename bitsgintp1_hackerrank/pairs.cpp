//https://www.hackerrank.com/contests/bitsgintp1/challenges/pairs/problem
##include <bits/stdc++.h>	//Includes all the necessary files by default (iostream, string, set, map, queue, etc.)
#include <cmath>
using namespace std;

int pair_count (vector< int >& array, map< int, int >& myMap, int& diff) {
	int result (0);
	for (auto i : array) {
		if (myMap [abs (i + diff)] == 1) { result++; }
	}

	return (result);
}

int main () {
	int size (0), diff (0);
	vector< int > array;
	map< int, int > myMap;

	cin >> size >> diff;
	for (int i = 0; i < size; i++) {
		int key (0);
		cin >> key;

		array.push_back (key);
		myMap [key] = 1;
	}

	cout << pair_count (array, myMap, diff) << endl;
}

/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int k;
    int out = 0;

    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
       if(binary_search (nums.begin(), nums.end(), nums[i] + k))
            out++;

    cout << out;

    return 0;
}*/
