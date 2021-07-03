#include <bits/stdc++.h>

using namespace std;

const int Nmax = 10'001;

long long maxSumSubarrayGreedy(int a[], int n)
{
    long long sum = 0, ans = a[1];
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        if(sum > ans)
            ans = sum;
        if(sum < 0)
            sum = 0;
    }
    return ans;
}
long long maxSumSubarrayPartialSums(int a[], int n)
{
    if(n == 0)
        return 0;

    long long s[Nmax], ans = a[1], minS = 0;

    s[1] = a[1];
    for(int i = 2; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    for(int i = 1; i <= n; i++)
    {
        if(s[i] - minS > ans)
            ans = s[i] - minS;
        if(s[i] < minS)
            minS = s[i];
    }
    return ans;
}
long long maxSumSubarrayKadaneAlgorithm(int a[], int n)
{
    long long globalSum = a[1],localSum=a[1];
    for(int i = 2; i <= n; i++)
    {
        localSum = max(1LL*a[i],a[i]+localSum);
        if(localSum > globalSum)
            globalSum = localSum;

    }
    return globalSum;
}

int main()
{
    //Example input
    //7
    //5 -6 3 4 -2 3 -3
    //Expected output
    //8
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << maxSumSubarrayGreedy(a, n)<<endl;
    cout << maxSumSubarrayPartialSums(a, n)<<endl;
    cout << maxSumSubarrayKadaneAlgorithm(a, n)<<endl;
    return 0;
}
