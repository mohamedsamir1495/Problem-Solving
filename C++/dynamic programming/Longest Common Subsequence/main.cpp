#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000, Mmax =1000;

int a[Nmax], b[Mmax], dp[Nmax][Mmax];

int findLCS(int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]= 1 + dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    return dp[n][m];
}

/// Can only be called after the db matrix is calculated
void reconstruct(int i,int j)
{
    if(i==0 || j==0) return;

    if(a[i] == b[j])
    {
        reconstruct(i-1,j-1);
        cout<<a[i]<<" ";
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
            reconstruct(i-1,j);
        else
            reconstruct(i,j-1);
    }
}
int main()
{
    ///Input
    /*
    8
    1 7 1 8 3 6 5 9
    4
    7 3 9 8
    */
    ///Output
    ///3
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    int m;
    cin>>m;
    for(int i=1; i<=m; i++) cin>>b[i];

    cout<<findLCS(n,m)<<endl;
    reconstruct(n,m);
    return 0;
}
