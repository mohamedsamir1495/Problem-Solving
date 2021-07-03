#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

const int nMax = 1000;

int freq[nMax];

int main()
{
    int n,input,distinctCount=0;
    cin >>n;
    for(int i=1; i<=n; i++)
    {
        cin>> input;

        if(freq[input]==0) distinctCount++;

        freq[input]++;
    }
    cout << "Distinct Numbers count : "<<distinctCount<<endl;

    int q,x;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>> x;
        cout << "This Number appeared : "<<freq[x]<<" th times"<<endl;
    }

    return 0;
}
