#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000;

int dp[Nmax];
int minLast[Nmax];

int findLis(int a[],int n)
{
    dp[1]=1;
    minLast[1]=a[1];

    int len=1;
    for(int i=2; i<=n; i++)
    {
        if(a[i]>minLast[len])
        {
            len++;
            dp[i]=len;
            minLast[len]=a[i];
        }
        else
        {
            int p = upper_bound(minLast+1,minLast+len+1,a[i]) - minLast;

            if(minLast[p-1]==a[i]) p--;

            dp[i]=p;

            minLast[p]=a[i];
        }
    }
    return len;
}
int main()
{
    ///Input
    /*
    6
    3 9 7 13 10 12
    */
    ///Output
    /// 4
    int n;
    cin>>n;

    int a[Nmax];

    for(int i=1;i<=n;i++) cin>>a[i];

    cout<<findLis(a,n);
    return 0;
}
