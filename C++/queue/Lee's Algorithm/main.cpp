#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000, Mmax= 1000;
bool a[Nmax][Mmax];

int n,m;

int dist[Nmax][Mmax];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int leeAlgo(pair<int,int>src,pair<int,int>dst)
{
    queue<pair<int,int>> Q;
    dist[src.first][src.second] = 1;
    Q.push(src);

    while(!Q.empty())
    {
        pair<int,int>cell = Q.front();
        if(cell == dst)
            return dist[cell.first][cell.second] - 1;
        Q.pop();
        for(int dis=0; dis<4; dis++)
        {
            if(a[cell.first+dx[dis]][cell.second+dy[dis]]==1 && dist[cell.first+dx[dis]][cell.second+dy[dis]]==0 )
            {
                dist[cell.first+dx[dis]][cell.second+dy[dis]] = dist[cell.first][cell.second]+1;
                Q.push(make_pair(cell.first+dx[dis],cell.second+dy[dis]));
            }

        }
    }
    return -1;
}
int main()
{
    ///Input
    /*
        9 9
        1 1 1 1 1 1 1 1 0
        1 1 1 0 1 0 0 1 1
        0 0 1 1 0 0 0 0 1
        0 1 1 0 0 1 1 0 1
        0 1 0 0 0 0 0 0 1
        1 1 0 0 1 1 1 1 1
        0 1 1 1 1 0 1 1 1
        0 1 0 0 1 0 1 0 0
        0 1 1 0 1 0 1 1 0

        6 5
        2 3
    */
    ///Output
    /// 10
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];

    pair<int,int>src,dist;
    cin>>src.first>>src.second;
    cin>>dist.first>>dist.second;

    cout<<leeAlgo(src,dist);
    return 0;
}
