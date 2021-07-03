#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100'005;

int ans[Nmax];

void buildAns(int a[],int n,int ans[])
{
    stack<int> S;
    for(int i=1; i<= n; i++)
    {
        while(!S.empty()&&a[S.top()]<a[i])
        {
            ans[S.top()] = i;
            S.pop();
        }
        S.push(i);
    }

}
int main()
{
    ///Input
    /*
        5
        1 2 3 4 5
    */
    ///Output
    /// 2 3 4 5 0
    int a[Nmax], ans[Nmax], n;
    cin>>n;

    for(int i=1; i<= n; i++) cin>>a[i];

    buildAns(a,n,ans);

    for(int i=1; i<= n; i++) cout<<ans[i]<<" ";
    return 0;
}
