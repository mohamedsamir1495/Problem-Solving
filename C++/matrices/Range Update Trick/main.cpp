#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

const int nMax = 1000;

int arr[nMax][nMax];
int aux[nMax][nMax];

void update(int x1,int y1,int x2,int y2, int val)
{
    aux[x1][y1]+=val;
    aux[x1][y2+1]-=val;
    aux[x2+1][y1]-=val;
    aux[x2+1][y2+1]+=val;
}

void buildFinalMatrix(int n,int m)
{
    // Compute the prefix sum of all columns
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            aux[i][j] += aux[i][j - 1];

    // Compute the prefix sum of all rows
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            aux[j][i] += aux[j - 1][i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            arr[i][j] += aux[i][j];

}
int main()
{
    int n,m;
    cin >>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>> arr[i][j];

    int q, x1,y1,x2,y2,value;
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>> x1>>y1>>x2>>y2>>value;
        update( x1, y1,x2, y2, value);
    }
    buildFinalMatrix(n,m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)  cout<< arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
