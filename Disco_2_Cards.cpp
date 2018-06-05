#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,m;
    cin>>n>>m;


    int arr[n][m]={{0}};
    //fill_n((int*)arr,n*m,0);
    //reading Input
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0; j<k;j++)
        {
            int q;
            cin>>q;
            arr[i][q-1]=1;
        }
    }
/*cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    if(m<pow(2,n))
    {
        cout<<"YES";
        return 0;
    }

    //int flag =0;

    int powset=pow(2,n);

    for(int i=0;i<powset;i++)
    {
        int sum_arr[m]={0};
        cout<<endl;
        for(int j=0;j<n;j++)
        {
            cout<<((i>>j)&(1))<<" ";
            if(i&(1<<j))
            {
                for(int k=0;k<m;k++)
                {
                    if(arr[j][k]==0)
                    {
                        sum_arr[k]+=1;
                    }
                }
            }
            else
            {
                for(int k=0;k<m;k++)
                {
                    if(!arr[j][k]==0)
                    {
                        sum_arr[k]+=1;
                    }
                }
            }
        }
        cout<<endl;
        int flag=0;
        for(int a=0;a<m;a++)
        {
            cout<<sum_arr[a]<<" ";
            if(sum_arr[a]==0)
            {


                flag=1;
                break;
            }
        }
        cout<<"\n";
        if(!flag)
        {
            cout<<"YES";
            return 0;
        }
    }

    cout<<"NO";
    return 0;
}
