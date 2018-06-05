#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,cyclen,current,next;
    cin >> n;
    int p[n+1];
    for(int i=1;i<=n;i++)
        cin >> p[i];
    int vis[n+1]={0};
    int cycles[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        cyclen=1;
        current = p[i];
        vis[current]=1;
        next = p[p[i]];
        while(next!=current)
        {
            vis[next]=1;
            next = p[next];
            cyclen++;
        }
        cycles[cyclen]++;
    }
    //for(int i=1;i<=n;i++)
        //cout<<cycles[i]<<" ";
    for(int i=2;i<=n;i+=2)
    {
        if(cycles[i]%2 == 1)
        {
            cout<<"NO ";
            return 0;
        }

    }
    cout << "YES ";




    return 0;
}
