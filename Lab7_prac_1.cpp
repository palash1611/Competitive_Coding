#include<bits/stdc++.h>
using namespace std;
#define lli long long int

bool check_min_heap(lli arr[],lli i,lli n)
{


  if(i>=(n-1)/2)
  return true;
  if(arr[i]<arr[2*i+1] && arr[i]<arr[2*i+2] && check_min_heap(arr,2*i+1,n)&& check_min_heap(arr,2*i+2,n))
  {
  //  cout<<h.arr[i]<<" "<<h.arr[2*i+1]<<" "<<h.arr[2*i+2]<<endl;
    return true;
  }
  return false;
}

bool check_max_heap(lli arr[],lli i,lli n)
{
  if(i>=(n-1)/2)
  return true;
  if(arr[i]>=arr[2*i+1] && arr[i]>=arr[2*i+2] && check_max_heap(arr,2*i+1,n)&& check_max_heap(arr,2*i+2,n))
  {
    //cout<<arr[i]<<" "<<arr[2*i+1]<<" "<<arr[2*i+2]<<endl;
    return true;
  }
  return false;
}

int main()
{
  lli n;
  cin>>n;
  lli key;

  lli arr[n];
  for(lli i=0;i<n;i++)
  {
    cin>>arr[i];
  }

//cout<<endl;
 if(check_min_heap(arr,0,n))
 cout<<"MINHEAP";
 else if(check_max_heap(arr,0,n))
 cout<<"MAXHEAP";
 else cout<<"NONE";

  return 0;
}
