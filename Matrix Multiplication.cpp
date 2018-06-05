// Matrix Multiplication
#include<bits/stdc++.h>
using namespace std;

void multi(int arr1[6][6],int arr2[6][6],int mult[6][6])
{
    
    
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            for(int k=0;k<6;k++)
                {
                    mult[i][j]+=arr1[i][k]*arr2[k][j];
                }
    
}
    int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int arr[6][6]={{0,0,0,1,1,1},{0,0,0,1,1,1},{0,0,0,1,1,1},{1,1,1,0,0,0},{1,1,1,0,0,0},{1,1,1,0,0,0}};
    int mult[6][6]={0};
        int mult2[6][6]={0};

    multi(arr,arr,mult);
        
    multi(mult,arr,mult2);
    
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
          cout<<mult2[i][j];
        }
        cout<<endl;
    }
    return 0;
}
