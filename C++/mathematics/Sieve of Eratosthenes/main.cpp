#include <bits/stdc++.h>

using namespace std;

const int Nmax = 100'001;
bool isPrime[Nmax];

void sieveOfEratosthenes(int number)
{
    for(int i=2; i<=number; i++) isPrime[i]=true;

    for(int i=2; i<=number/2; i++)
    {
        if(isPrime[i])
            for(int j=i * 2; j<= number; j+=i)isPrime[j] =false;
    }
}
int main()
{
    const int n = 2;
    sieveOfEratosthenes(n);
    for(int i=2; i<=n; i++)
        if(isPrime[i])
            cout<<i<<" ";
    return 0;
}
