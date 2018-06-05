#include <bits/stdc++.h>
using namespace std;

void swap (int *x,int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void SelectionSort(int arr[], int n)
{
  for(int i=0;i<n;i++)
  {
    int min_index = i;

    for (int j=i+1;j<n;j++)
    {
      if (arr[j]<arr[min_index])
      {
        min_index=j;
      }
    }

    swap(&arr[min_index],&arr[i]);
  }
}

void BubbleSort(int arr[],int n)
{

  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      swap(&arr[j],&arr[j+1]);
    }
  }
}

void InsertionSort(int arr[],int n)
{
  int i , j , key;

  for(i=1;i<n;i++)
  {
    key=arr[i];
    j=i-1;
    while(j>=0 & arr[j]>key)
    {
      arr[j+1]=arr[j];
    }

    arr[j+1]=key;
  }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int arr[] = {64, 25, 12, 22, 11};
    int arr_len=sizeof(arr)/sizeof(arr[0]);
    //sort(arr,arr+arr_len);
    //SelectionSort(arr,5);
    //InsertionSort(arr,5);
    //BubbleSort(arr,5);
    for(int i=0;i<5;i++)
    {
      cout<<arr[i]<<" ";
    }

    return 0;
}
