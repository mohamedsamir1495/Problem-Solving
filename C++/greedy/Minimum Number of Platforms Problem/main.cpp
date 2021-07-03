#include <bits/stdc++.h>

using namespace std;

int minPlatforms(vector<pair<double,double> >trains)
{
    vector<pair<double,int>>events;
    for(pair<double,double>tr:trains)
    {
        events.push_back(make_pair(tr.first,1));
        events.push_back(make_pair(tr.second,0));
    }
    sort(events.begin(),events.end());
    int ans=0,free_plat=0;

    for(pair<int,int>ev:events)
    {
        if(ev.second == 0)
            free_plat++;
        else
        {
            if(free_plat==0)
                ans++;
            else
                free_plat--;
        }
    }
    return ans;
}
int main()
{
    ///Input
    /*
        6
        2 2.30
        2.10 2.40
        3.00 3.20
        3.20 4.30
        3.50 4
        5 5.20
    */
    ///Output
    /// 2

    int n;
    cin>>n;
    vector<pair<double,double>>trains(n);

    for(int i=0; i<n; i++)
        cin>>trains[i].first>>trains[i].second;

    cout<<minPlatforms(trains);
    return 0;
}
