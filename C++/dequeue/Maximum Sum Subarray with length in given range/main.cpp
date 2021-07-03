#include <bits/stdc++.h>

using namespace std;

int maxSum(vector<int> a,int n,int A,int B)
{
    vector<int>s(n+1);
    int ans=0;
    s[0]=0;
    for(int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    deque<int>dq;
    dq.push_back(0);
    for(int right = 1; right<=n; right++)
    {
        if(!dq.empty() &&dq.front() < right - B)
            dq.pop_front();
        if(right >= A)
            ans = max(ans,s[right]-s[dq.front()]);
        while(!dq.empty() && s[dq.back()] >= s[right])
            dq.pop_back();

        dq.push_back(right);
    }
    return ans;
}
int main()
{
    ///Input
    /*
    7 2 4
    2 -9 7 -2 8 -1 1
    */
    ///Output
    /// 13
    int n,A,B;
    cin>>n>>A>>B;

    vector<int>a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    cout<<maxSum(a,n,A,B);
    return 0;
}
