#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int minMoves(string s,int k)
{
    int left=1;
    while(s[left]=='0' && left <s.length()) left++;

    if(left==s.length()) return 0;

    int right,moves=0;

    bool lastOneInArr=false;
    for(right=left+1; right<s.length(); right++)
    {
        if(s[right]=='1')
            lastOneInArr=false;

        if(s[right]=='1'&&right-left<k)
        {
            s[right]='0';
            moves++;
        }
        else if(s[right]=='0'&&right-left==k)
        {
            while(right<s.length()&&s[right]=='0')
                right++;
            right--;

            if(right==s.length()-1) break;

            else moves += (right-left)/k;

            left = right = right - ((right-left)%k);
        }
        else if(s[right]=='1'&&right-left==k)
        {
            left=right;
        }
    }
    return moves;
}
int main()
{
    int t;
    cin>>t;

    int n,k;
    string s;
    for(int i=0; i<t; i++)
    {
        cin>>n>>k;
        cin>>s;
        cout<<"t = "<<i+1<<endl;
        cout<<minMoves('-'+s,k)<<endl;
    }

    return 0;
}
