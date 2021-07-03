#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1000005;
const int INF = 1'000'000'000;
const int MOD = 998244353;

int a[Nmax];

void fix(int &x) {
    if(x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    int tests, n;
    cin >> tests;
    while(tests--) {
        cin >> n;
        vector<bool> rest(n + 1, false);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int i;
        for(i = 0; i < n; i++) {
            int x = a[i];
            if(x < 0) {
                x = (1LL * INF * n + x) % n;
            }
            if(rest[(i + x) % n] == true) {
                cout << "NO\n";
                break;
            }
            rest[(i + x) % n] = true;
        }
        if(i == n) {
            cout << "YES\n";
        }
    }
    return 0;
}
