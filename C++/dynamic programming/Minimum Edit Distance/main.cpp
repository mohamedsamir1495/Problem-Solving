#include <bits/stdc++.h>

using namespace std;


const int Nmax = 1000;
const int Mmax = 1000;

int dp[Nmax][Mmax];

int minEditDistance(string s1,string s2,int c1, int c2, int c3)
{
    int n=s1.size(), m=s2.size();

    for(int j=0; j<=m; j++) dp[0][j] = j * c1;

    for(int i=0; i<=n; i++) dp[i][0] = i * c2;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            dp[i][j]=c1+dp[i][j-1]; ///insertion
            dp[i][j] = min(dp[i][j],c2+dp[i-1][j]); ///deletion
            dp[i][j] = min(dp[i][j],c3+dp[i-1][j-1]); ///replacement

            if(s1[i-1]==s2[j-1]) ///nothing to be done
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
        }

    return dp[n][m];
}
int main()
{
    ///NB : He didnt give a cost for c1,c2,c3 so i assumed 1, 2, 3 for the given scenario
    ///Input
    /*
     1 2 3
     sunday
     saturday
    */
    ///Output
    ///5
    int c1,c2,c3;
    cin>>c1>>c2>>c3;
    string s1,s2;
    cin>>s1>>s2;
    cout<<minEditDistance(s1,s2,c1,c2,c3);
    return 0;
}
