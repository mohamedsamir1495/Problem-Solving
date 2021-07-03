#include <bits/stdc++.h>

using namespace std;

int killMonsters(int Hp,int k, vector<int>dmg)
{
    priority_queue<int>kills;
    for(int i=0; i<dmg.size(); i++)
    {
        if(dmg[i] <=0)
        {
            Hp+= -dmg[i];
            continue;
        }
        Hp-=dmg[i];
        kills.push(dmg[i]);
        while(Hp<=0 && k > 0 && kills.empty()==false)
        {
            Hp+=kills.top();
            kills.pop();
            k--;
        }
        if(Hp < 0) return i;
        if(Hp == 0) return i+1;

    }
    return dmg.size();
}

int main()
{
    ///Input
    /*
        10 2 10
        -3 2 3 -2 8 8 6 4 3 3 3
    */
    ///Output
    /// 8
    int n,k,x;

    cin>>n>>k>>x;
    vector<int>dmg(n);

    for(int i=0; i<n; i++)
        cin>>dmg[i];

    cout<<killMonsters(x,k,dmg);
    return 0;
}
