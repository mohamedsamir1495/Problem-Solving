#include <bits/stdc++.h>

using namespace std;



long long maxRectArea(vector<int>h)
{
    int n= h.size();
    vector<int>left(n,-1), right(n,n);
    stack<int>st,emptySt;
    for(int i=0; i<n; i++)
    {
        while(!st.empty()&&h[i]<h[st.top()])
        {
            right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    st = emptySt;
    for(int i=n-1; i >=0; i--)
    {
        while(!st.empty()&&h[i]<h[st.top()])
        {
            left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    long long ans =0;
    for(int k=0; k<n; k++)
        ans = max(ans,h[k]*(right[k]-left[k]-1)*1LL);
    return ans;
}


long long maxSizeRect(vector<vector<int>> a,int n,int m)
{
    long long ans=0;
    vector<vector<int>> tower(n+1,vector<int>(m+1));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i][j] == 0)
                tower[i][j] =0;
            else
                tower[i][j] = 1+ tower[i-1][j];

    for(int i=1; i<=n; i++)
        ans = max(ans,maxRectArea(tower[i]));

    return ans;
}

int main()
{
    ///Input
    /*
    4 7
    1 1 0 1 1 0 1
    1 1 1 0 1 1 1
    1 1 1 1 1 1 1
    0 1 1 1 1 0 1
    */
    ///Output
    /// 8
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>a[i][j];
    cout<<maxSizeRect(a,n,m);
    return 0;
}
