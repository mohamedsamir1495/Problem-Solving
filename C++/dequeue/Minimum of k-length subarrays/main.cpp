#include <bits/stdc++.h>

using namespace std;

vector<int>findMins(vector<int>a,int n,int k)
{
    deque<int>dq;
    vector<int>ans;
    for(int i=1; i<=n; i++)
    {
        while(!dq.empty() && a[dq.back()]>=a[i])
            dq.pop_back();
        if(!dq.empty() && dq.front() == i-k)
            dq.pop_front();

        dq.push_back(i);
        if(i >=k)
            ans.push_back(a[dq.front()]);
    }
    return ans;
}
int main()
{
    ///Input
    /*
    9 3
    -7 9 2 4 -1 5 6 7 1
    */
    ///Output
    /// -7 2 -1 -1 -1 5 1
    int n,k;
    cin>>n>>k;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int>ans = findMins(a,n,k);

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
