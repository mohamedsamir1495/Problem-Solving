#include <bits/stdc++.h>

using namespace std;

int main()
{
    ///Input
    /*
    7 7
    3 -2 9 3 -2 4 9
    */
    ///Output
    /// 6
    int n,S;
    cin>>n>>S;
    unordered_map<int,int>myMap;
    vector<int>a(n);

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        myMap.insert(make_pair(a[i],0));
    }
    int ans=0;
    for(int j=0; j<n; j++)
    {
        ans+= myMap[S-a[j]];
        myMap[a[j]]++;
    }
    cout<<ans;

    return 0;
}
