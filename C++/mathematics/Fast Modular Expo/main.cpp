#include <bits/stdc++.h>

using namespace std;

int fastExpoRecursive(int a, long long n, int MOD)
{
    // (a^n) % MOD
    if(n == 0)
        return 1;

    if(n %2==0)
        // a ^ n = (a^2)^(n/2)
        return fastExpoRecursive((1LL*a*a)%MOD,n/2,MOD);

    //  a ^ n = a * ( a ^ (n-1) )
    return (1ll* a * fastExpoRecursive(a,n-1,MOD))%MOD;

}

int fastExpoIterative(int a, long long n, int MOD)
{
    // (a^n) % MOD
    int ans = 1;

    while(n>=1)
    {
        // a ^ n = (a^2)^(n/2)
        if(n %2==0)
        {
            a=(1LL*a*a)%MOD;
            n/=2;
        }
        //  a ^ n = a * ( a ^ (n-1) )
        else
        {
            ans=(1LL*ans*a)%MOD;
            n--;
        }
    }
    return ans;
}

int main()
{
    cout << fastExpoRecursive(7,10,1000'000'007) << endl;
    cout << fastExpoIterative(7,10,1000'000'007) << endl;
    return 0;
}
