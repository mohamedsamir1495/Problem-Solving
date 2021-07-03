#include <bits/stdc++.h>

using namespace std;

int typeOf(char c)
{
    if(c == '(' || c == ')' ) return 0;
    if(c == '[' || c == ']' ) return 1;
    return 2;
}
bool validParentheses(string s)
{
    stack<char> S;
    for(int i=0; i<s.size(); i++)
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            S.push(s[i]);
        else if(!S.empty() && typeOf(S.top()) == typeOf(s[i]))
            S.pop();
        else
            return false;

    return S.empty();
}

int main()
{
    ///Input
    /// ({[]})
    /// Output
    /// 1
    string s;
    cin>>s;
    cout<<validParentheses(s);
    return 0;
}
