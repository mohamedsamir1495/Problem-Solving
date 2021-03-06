#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>vec,int w,int b)
{
    sort(vec.begin(),vec.end());
    int ans=0,n=vec.size(),p=0;
    vector<bool>isTaken(n,false);
    priority_queue< pair<int,int> >pq;
    for(int i=n-1; i>=0; i--)
    {
        while(p<i&&vec[p]+vec[i]<=w)
            pq.push({vec[p],p++});
        if(isTaken[i])continue;
        while(!pq.empty()&&vec[i]-pq.top().first<=b)
        {
            if(isTaken[pq.top().second] || pq.top().second == i)
            {
                pq.pop();
                continue;
            }
            isTaken[i]=isTaken[pq.top().second]=true;
            pq.pop();
            break;
        }
        ans++;
    }
    return ans;
}

int main()
{
    ///Input
    /*
    8 100 10
    81 37 32 88 55 93 45 72
    */
    ///Output
    /// 6
    int n,w,b;

    cin>>n>>w>>b;
    vector<int>vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    cout<<solve(vec,w,b);

    return 0;
}
