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

ll a[15], f[105];

void Prepare() {
    f[1] = 10;

    FOR(i, 1, 9) {
        a[i] = 1;
    }

    FOR(i, 2, 100) {
        FOR(j, 1, 9) {
            ll s = 0;

            FOR(k, j, 9) {
                s += a[k];
            }

            a[j] = s;
            f[i] = (f[i] + a[j]) % MOD;
        }
    }

    FOR(i, 2, 100) {
        f[i] = (f[i] + f[i - 1]) % MOD;
    }
}

void run_case() {
    int n;
    cin >> n;

    cout << f[n] << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;
    cin >> T;

    Prepare();

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}