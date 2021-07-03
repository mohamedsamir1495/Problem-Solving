#include <bits/stdc++.h>

using namespace std;

long long connectRopes(vector<int>ropes)
{
    long long ans=0;
    priority_queue<int>pq;
    for(int rope: ropes)
        pq.push(-(rope));

    for(int step=1; step<ropes.size(); step++)
    {
        int min1 = -pq.top();
        pq.pop();
        int min2 = -pq.top();
        pq.pop();
        ans+= min1+min2;
        pq.push(-(min1+min2));
    }
    return ans;
}
int main()
{
    ///Input
    /*
    4
    4 3 2 6
    */
    ///Output
    /// 29
    int n;
    cin>>n;
    vector<int>ropes(n);
    for(int i=0; i<n; i++) cin>>ropes[i];
    cout<<connectRopes(ropes);
    return 0;
}
