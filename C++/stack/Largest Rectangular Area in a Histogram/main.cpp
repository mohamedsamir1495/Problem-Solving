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
    for(int k=0;k<n;k++)
        ans = max(ans,h[k]*(right[k]-left[k]-1)*1LL);
    return ans;
}
int main()
{
    ///Input
    /*
    7
    6 2 5 4 5 1 6
    */
    ///Output
    /// 12
    int n;
    cin>>n;
    vector<int>h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<maxRectArea(h);
    return 0;
}
