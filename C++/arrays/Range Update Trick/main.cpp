#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

const int nMax = 1000;

int a[nMax];
int b[nMax];
long long s[nMax];

void update(int x,int y, int val)
{
    b[x]+=val;
    b[y+1]-=val;
}
void buildFinalArray(int n)
{
    for(int i=1; i<=n; i++)
    {
        s[i]=s[i-1]+b[i];
        a[i]+=s[i];
    }
}
int main()
{
    int n;
    cin >>n;
    for(int i=1; i<=n; i++) cin>> a[i];

    int q, x,y,value;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>> x >> y >> value;
        update(x,y,value);
    }
    buildFinalArray(n);
    for(int i=1; i<=n; i++) cout<< a[i]<<" ";
    return 0;
}
