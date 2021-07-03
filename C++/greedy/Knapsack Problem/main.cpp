#include <bits/stdc++.h>

using namespace std;


const int Nmax = 100'000;

struct obj
{
    int w;
    double vpu;

    bool operator < (const obj&x) const
    {
        return vpu > x.vpu;
    }

};

obj a[Nmax];

int main()
{
    ///Input
    /*
    7 10
    10 2
    5 3
    15 5
    7 7
    6 1
    18 4
    3 1
    */
    ///Output
    /// 43
    int n,G;
    cin>>n>>G;
    for(int i=1; i<=n; i++)
    {
        int v,w;
        cin>>v>>w;
        a[i].w=w;
        a[i].vpu = (double)v/w;
    }

    sort(a+1,a+n+1);
    double ans =0 ;
    for(int i=1; i<=n; i++)
    {
        int q = min(a[i].w,G);
        ans+=q*a[i].vpu;
        G-=q;
    }
    cout<<ans;
    return 0;
}
