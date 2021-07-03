#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

const int nMax = 1'000;

int a[nMax];
long long s[nMax];

void buildPartialSums(int a[],int n)
{
    s[0]=a[0];
    for(int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
}
long long query(int x,int y)
{
    return s[y]-s[x-1];
}
int main()
{
    int n;
    cin >>n;
    for(int i=1; i<=n; i++) cin>> a[i];
    buildPartialSums(a,n);

    int q, x,y;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>> x >> y;
        cout<<query(x,y)<<endl;
    }

    return 0;
}
