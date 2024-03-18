#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
#define ppb pop_back
#define endl '\n'
#define fi first
#define se second

#ifdef Juhan404
#include "debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

string a, b;
int dp[105][105];

void run_case() {
    memset(dp, 0, sizeof(dp));

    cin >> a >> b;
    int n = sz(a), m = sz(b);
    a = " " + a;
    b = " " + b;

    FOR(i, 1, m) {
        dp[0][i] = i;
    }
    FOR(i, 1, n) {
        dp[i][0] = i;
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        }
    }

    cout << dp[n][m] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;
    cin >> T;

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}