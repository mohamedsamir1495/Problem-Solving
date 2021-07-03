#include <bits/stdc++.h>

using namespace std;

int bSearch(int a[],int n, int target)
{
    int left = 1, right = n, mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(a[mid]==target)
            return mid;
        else if(a[mid]<target)
            left=mid+1;
        else
            right = mid-1;

    }
    return -1;
}
int main()
{
    int arr[6] = {0,1,2,3,4,100};
    cout<<bSearch(arr,5,100);
    return 0;
}
