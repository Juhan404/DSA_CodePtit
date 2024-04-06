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
    int n;
    cin >> n;

    vector<int> f(n + 5, 1);
    pair<double, double> p[n + 5];
    int res = 0;

    FOR(i, 1, n) {
        cin >> p[i].fi >> p[i].se;

        FOR(j, 1, i - 1) {
            if (p[i].fi > p[j].fi && p[i].se < p[j].se && f[i] <= f[j])
                f[i] = f[j] + 1;
        }

        res = max(res, f[i]);
    }

    cout << res << endl;
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