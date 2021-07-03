#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000;
const int Gmax = 1000;

int dp[Nmax][Gmax];

int knapsackProblem(int w[],int v[],int n,int Gmax)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=Gmax; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(w[i]<=j)
                dp[i][j] = max(dp[i][j],v[i]+dp[i-1][j-w[i]]);
        }
    int ans=0;
    for(int j=0; j<=Gmax; j++)
        ans=max(ans,dp[n][j]);

    return ans;
}
int main()
{
    ///Input
    /*
    6 10

    3 7
    3 4
    1 2
    1 9
    2 4
    1 5
    */
    ///Output
    ///29
    int n,Gmax,w[Nmax],v[Nmax];
    cin>>n>>Gmax;
    for(int i=1; i<=n; i++)
        cin>>w[i]>>v[i];

    cout<<knapsackProblem(w,v,n,Gmax);

    return 0;
}
