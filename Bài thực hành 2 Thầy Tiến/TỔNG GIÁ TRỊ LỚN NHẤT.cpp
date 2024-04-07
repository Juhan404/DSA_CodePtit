#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
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

const ll INF = 1e9 + 69;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

void run_case() {
    int n, s;
    cin >> n >> s;

    vector<int> w(n + 1, 0), v(n + 1, 0);

    FOR(i, 1, n) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> f(n + 1, vector<int>(s + 1, 0));

    FOR(i, 1, n) {
        FOR(j, 1, s) {
            f[i][j] = f[i - 1][j];

            if (j >= w[i])
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << f[n][s] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int test = 1;

    for (int tc = 1; tc <= test; tc++) {
        // cout << "Test #" << tc << ": ";
        run_case();
    }
    return 0;
}