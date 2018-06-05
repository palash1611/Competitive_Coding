
#include<bits/stdc++.h>
using namespace std;
#define lli long long int

void swap(int *x, int *y);

class MinHeap
{
  public:
    int *arr;
    int capacity;
    int size;

    MinHeap(int capacity);

    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    int left(int i) { return (2*i + 1); }

    int right(int i) { return (2*i + 2); }

    int extractMin();

    void decreaseKey(int i, int new_val);

    int getMin() { return arr[0]; }

    void deleteKey(int i);

    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    size = 0;
    capacity = cap;
    arr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (size == capacity)
    {
        cout << "\nOverflow\n";
        return;
    }

    size++;
    int i = size - 1;
    arr[i] = k;

    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(&arr[i], &arr[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
       swap(arr[i], arr[parent(i)]);
       i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if (size <= 0)
        return INT_MAX;
    if (size == 1)
    {
        size--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size-1];
    size--;
    MinHeapify(0);

    return root;
}


void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < size && arr[l] < arr[i])
        smallest = l;
    if (r < size && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    lli temp = *x;
    *x = *y;
    *y = temp;
}

void print(MinHeap h)
{
  for(int i=0;i<h.size;i++)
  {
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
    lli n,ky;
    cin>>n;
    lli fin_arr[n]={0};

    lli arr[3][n];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>ky;
            fin_arr[j]+=ky;
        }
    }

//cout<<endl;





    MinHeap h(n);
    for(int i=0;i<n;i++)
    {
      h.insertKey(fin_arr[i]);
    }

    lli q;
    cin>>q;

    for(int i=0;i<q;i++)
    {

      lli k;
      cin>>k;
      if(k>h.size)
      {
        cout<<-1;
        continue;
      }

      lli brr[k-1]={0};
      for(lli  i=0;i<k-1;i++)
      {
        brr[i]=h.extractMin();
      }
      cout<<h.arr[0];
      h.extractMin();
      for(lli i=0;i<k-1;i++)
      {
        h.insertKey(brr[i]);
      }

    }

    return 0;
}
