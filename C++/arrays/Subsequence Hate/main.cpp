#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
int main()
{
    int tests;
    cin >> tests;
    string s;
    while(tests--) {
        cin >> s;
        int total_0 = 0, total_1 = 0;
        for (int j = 0; j < s.length(); j++) {
            total_0 += (s[j] == '0');
            total_1 += (s[j] == '1');
        }
        int ans = min(total_0, total_1);

        int nl_0 = 0, nl_1 = 0;
        for (int j = 0; j < s.length(); j++) {
            nl_0 += (s[j] == '0');
            nl_1 += (s[j] == '1');

            ans = min(ans, nl_0 + total_1 - nl_1);
            ans = min(ans, nl_1 + total_0 - nl_0);
        }
        cout << ans << endl;
    }
    return 0;
}
