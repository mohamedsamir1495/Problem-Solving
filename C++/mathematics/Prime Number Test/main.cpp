#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number)
{
    if(number <=1)
        return false;

    int sqrtNumber = sqrt(number);
    for (int a = 2; a <= sqrtNumber; a++)
        if (number % a == 0)
            return false;
    return true;
}

int main()
{
    cout <<isPrime(3);
    return 0;
}
