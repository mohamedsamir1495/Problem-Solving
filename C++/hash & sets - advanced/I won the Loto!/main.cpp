#include <bits/stdc++.h>

using namespace std;

vector<int> findSum(vector<int>nums, int S)
{
    int n = nums.size();
    unordered_set<int>mySums;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            for(int k=j; k<n; k++)
                mySums.insert(nums[i]+nums[j]+nums[k]);

    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            for(int k=j; k<n; k++)
                if(mySums.find(S-(nums[i]+nums[j]+nums[k]))!= mySums.end())
                {
                    for(int a=0; a<n; a++)
                        for(int b=a; b<n; b++)
                            for(int c=b; c<n; c++)
                                if(nums[a]+nums[b]+nums[c]== S-(nums[i]+nums[j]+nums[k]))
                                    return {nums[i],nums[j],nums[k],nums[a],nums[b],nums[c]};
                }
    return {};
}

vector<int> findSum2(vector<int>nums, int S)
{
    int n = nums.size();
    unordered_map<int,vector<int> >mySums;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            for(int k=j; k<n; k++)
                mySums[nums[i]+nums[j]+nums[k]] = {nums[i],nums[j],nums[k]};

    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            for(int k=j; k<n; k++)
                if(mySums.find(S-(nums[i]+nums[j]+nums[k]))!= mySums.end())
                {
                    vector<int> v = mySums[S-(nums[i]+nums[j]+nums[k])];
                    return {nums[i],nums[j],nums[k],v[0],v[1],v[2]};
                }
    return {};
}

int main()
{
    ///Input
    /*
    5 21
    3 7 2 -1 -10
    */
    ///Output
    /// 3 3 3 3 7 2
    int n, S;
    cin>>n>>S;
    vector<int>nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    vector<int>ans = findSum(nums,S);
    vector<int>ans2 = findSum2(nums,S);
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=0; i<ans2.size(); i++) cout<<ans2[i]<<" ";
    return 0;
}
