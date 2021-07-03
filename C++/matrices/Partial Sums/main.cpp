#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int nMax = 1'000;

int arr[nMax][nMax];
int pS[nMax][nMax];

void buildPartialSumArray(int n,int m)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            pS[i][j] = pS[i][j-1] + pS[i-1][j] + arr[i][j] - pS[i-1][j-1];
}

int calculateSum(int x1,int y1,int x2,int y2)
{
    return pS[x2][y2] - pS[x1-1][y2] - pS[x2][y1-1] + pS[x1-1][y1-1];
}
int main()
{
    /*
    Input
        6 6
        1 7 12 10 1 0
        11 7 -10 1 3 13
        -2 9 -5  2 4 7
        4 14 -9 3 13 -16
        -7 -8 -9 12 6 4
        2 -13 10 11 8 7
        1
        3 2 5 4

    Output
        9
    */
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];


    buildPartialSumArray(n,m);

    int t;
    cin>>t;
    int x1, y1, x2, y2;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<calculateSum(x1,y1,x2,y2)<<endl;
    }
    return 0;
}
