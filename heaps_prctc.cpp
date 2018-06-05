#include<bits/stdc++.h>
using namespace std;

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
    int temp = *x;
    *x = *y;
    *y = temp;
}

void k_largest(MinHeap h,int k)
{
  MinHeap newh(k);

  for(int i=0;i<k;i++)
  {
    newh.insertKey(h.arr[i]);
  }

  for(int i=k;i<h.size;i++)
  {
    if(newh.arr[0]<h.arr[i])
    swap(&newh.arr[0],&h.arr[i]);
    newh.MinHeapify(0);
  }

  for(int i=0;i<k;i++)
  {
    cout<<newh.arr[i]<<" ";
  }
}

void print(MinHeap h)
{
  for(int i=0;i<h.size;i++)
  {
    cout<<h.arr[i]<<" ";
  }
  cout<<endl;
}

void nearly_sorted(int harr[],int n,int k)
{

  MinHeap h(k+1);

  for(int i=0;i<k+1;i++)
  {
    h.insertKey(harr[i]);
  }

  int out[n];

  for(int i=k+1;i<n;i++)
  {
      cout<<h.getMin()<<" ";
      h.arr[0]=harr[i];
      h.MinHeapify(0);
  }
  while(h.size!=0)
  {
    cout<<h.arr[0]<<" ";
    h.extractMin();
  }
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);

    h.insertKey(2);

    h.deleteKey(1);

    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout<<"Printing  ";print(h);
    cout <<"extract min "<< h.extractMin() << " "<<endl;

    cout<<endl;
    cout<<"Printing   ";print(h);
    cout<<endl;

    cout <<"Get min "<< h.getMin() << " "<<endl;

    cout<<endl;
    cout<<"Printing   ";print(h);
    cout<<endl;

    cout<<"decrease key(2,1)  ";h.decreaseKey(2, 1);
    cout<<endl;
    cout<<endl;
    cout<<"Printing   ";print(h);
    cout<<endl;
    cout <<"get min "<< h.getMin();
    cout<<endl;cout<<endl;
    cout<<"Printing   ";print(h);
    cout<<endl;
    cout<<"k largest  ";
    k_largest(h,3);

    cout<<endl;cout<<endl;
    int karr[8]={3,4,1,6,2,8,5,7};
    cout<<"nearly sorted array ";
    nearly_sorted(karr,8,3);



    return 0;
}
