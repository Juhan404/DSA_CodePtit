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

void run_case() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x %= k;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k, -1e9));
    dp[0][a[0]] = 1;

    FOR(i, 1, n - 1) {
        FOR(j, 0, k - 1) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] + k) % k] + 1);
        }
    }

    cout << dp[n - 1][0] << endl;
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