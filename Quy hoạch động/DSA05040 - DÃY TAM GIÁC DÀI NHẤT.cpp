#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define sz(x) (int)(x).size()
#define pb push_back
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

    vector<int> a(n + 5, 0);
    FOR(i, 1, n) {
        cin >> a[i];
    }

    vector<int> inc(n + 5, 1);
    FOR(i, 2, n) {
        if (a[i] > a[i - 1])
            inc[i] = inc[i - 1] + 1;
    }

    vector<int> dec(n + 5, 1);
    ROF(i, n - 1, 1) {
        if (a[i] > a[i + 1])
            dec[i] = dec[i + 1] + 1;
    }

    int res = -1;
    FOR(i, 1, n) {
        res = max(res, inc[i] + dec[i] - 1);
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

    for (int test = 1; test <= T; test++) {

        run_case();
    }
    return 0;
}