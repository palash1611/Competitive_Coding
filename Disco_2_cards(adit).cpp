#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //return 0;
    int N, M;
    cin>>N;
    cin>>M;
    if(M<pow(2,N))
    {
        cout<<"YES";
        return 0;
    }

    //cout<<N;
    int cards[N][M];
    fill_n((int*)cards,M*N,0);
    for(int i=0;i<N;i++)
    {
        int k;
        cin>>k;
        for(int j=0; j<k;j++)
        {
            int n;
            cin>>n;
            cards[i][n-1]=1;
        }
    }


    int powset=pow(2,N);
    //cout<<powset;
    for(int count=0;count<powset;count++)
    {
        //xor=0;
        int sum[M]={0};
        fill_n(sum,M,0);
        /*cout<<"\n";
        for(int y=0;y<M;y++)
            cout<<sum[y]<<" ";*/
        cout<<"\n";
        for(int j=0;j<N;j++)
        {
            cout<<((count>>j) & (1))<<" ";
            if(count & (1<<j))
            {

                for(int a=0;a<M;a++)
                {
                    if(cards[j][a]==0)
                        sum[a]+=1;
                }

            }
            else
            {
                for(int a=0;a<M;a++)
                {
                    if(!cards[j][a]==0)
                        sum[a]+=1;
                }

            }

        }
        int flag=0;
        cout<<"\n";
        for(int a=0;a<M;a++)
        {
             cout<<sum[a]<<" ";

            if(sum[a]==0)
            {
                flag=1;
                break;
            }
        }
        cout<<"\n";
        if (!flag)
        {
            cout<<"YES";
            return 0;
        }


    }
    cout<<"NO";
    return 0;
}
