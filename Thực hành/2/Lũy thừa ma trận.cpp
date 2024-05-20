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

ll n, k;

struct matrix {
    ll res[15][15];
    friend matrix operator*(matrix a, matrix b) {
        matrix c;
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                c.res[i][j] = 0;
                FOR(k, 1, n) {
                    c.res[i][j] = (c.res[i][j] + a.res[i][k] * b.res[k][j]) % MOD;
                }
            }
        }
        return c;
    }
};

matrix powmod(matrix a, ll b) {
    if (b == 1)
        return a;
    matrix c = powmod(a, b / 2);

    if (b & 1)
        return c * c * a;
    else
        return c * c;
}

void run_case() {
    cin >> n >> k;
    matrix a;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            cin >> a.res[i][j];
        }
    }

    a = powmod(a, k);
    ll ans = 0;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            if (j == i)
                ans = (ans + a.res[i][j]) % MOD;
        }
    }
    cout << ans << endl;
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