#include <bits/stdc++.h>

#define endl "\n"

using namespace std;


int n, m;
string ans;
vector<string>testCases[100];

bool isValid(int test)
{
    for(int i = 1; i < n; i++)
    {
        int cnt = 0;
        for(int j = 0; j < m; j++)
        {
            cnt += (ans[j] != testCases[test][i][j]);
        }
        if(cnt > 1)
        {
            return false;
        }
    }
    return true;
}
string generateValidString(int test)
{
    for(int i = 0; i < m; i++)
    {
        for(char c = 'a'; c <= 'z'; c++)
        {
            if(c != testCases[test][0][i])
            {
                ans[i] = c;
                if(isValid(test))
                    return ans;
            }
        }
        ans[i] = testCases[test][0][i];
    }
    return "-1";
}
int main()
{
    int t;
    cin >> t;
    string s;
    for(int test=0; test<t; test++)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin>>s;
            testCases[test].push_back(s);
        }
        ans=testCases[test][0];

        if(isValid(test))
            cout <<ans<<endl;

        else
            cout<<generateValidString(test)<<endl;
    }
    return 0;
}
