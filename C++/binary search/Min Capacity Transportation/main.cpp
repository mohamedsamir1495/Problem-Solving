#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100'005;
int maxVal(int a[],int n)
{
    int maxVal = a[1];
    for(int i=2; i<=n; i++)
        maxVal = max(maxVal,a[i]);
    return maxVal;
}
long long sumOf(int a[],int n)
{
    long long sum = 0;
    for(int i=1; i<=n; i++)
        sum+=a[i];
    return sum;
}
int numOfRides(int a[],int n, long long c)
{
    int ans = 1;
    long long sum =0;
    for(int i=1; i<=n; i++)
    {
        if(sum + a[i] <= c)
            sum+= a[i];
        else
        {
            ans++;
            sum = a[i];
        }
    }
    return ans;
}
long long bSearch(int a[],int n, int k)
{
    long long left = maxVal(a,n), right= sumOf(a,n),ans;
    while(left<=right)
    {
        long long mid = (left+right)/2;
        if(numOfRides(a,n,mid)>k)
            left = mid+1;
        else
        {
            ans=mid;
            right = mid-1;
        }
    }
    return ans;

}
int main()
{
    ///Input
    /*
    6 3
    7 3 2 3 1 4
    */
    ///Output
    /// 8
    int n,k,arr[Nmax];
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>arr[i];
    cout<<bSearch(arr,n,k)<<endl;
    return 0;
}
