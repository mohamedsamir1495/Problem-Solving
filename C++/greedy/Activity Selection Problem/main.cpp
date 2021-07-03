#include <bits/stdc++.h>

using namespace std;


const int Nmax = 100'000;
struct Activity
{
    int start, finish;
    bool operator < (const Activity&x) const
    {
        return finish <x.finish;
    }
};

Activity act[Nmax];
int main()
{
    ///Input
    /*
        6
        1 2
        3 4
        0 6
        5 7
        8 9
        5 9
    */
    ///Output
    /// 4

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>act[i].start;
        cin>>act[i].finish;
    }
    sort(act+1,act+n+1);

    int ans=0,curFinish=-1;
    for(int i=1;i<=n;i++){
        if(curFinish <act[i].start){
            ans++;
            curFinish = act[i].finish;
        }
    }
    cout<<ans;
    return 0;
}
