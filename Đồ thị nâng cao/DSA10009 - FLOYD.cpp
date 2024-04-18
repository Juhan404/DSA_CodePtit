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

int n, m, q;
int d[105][105];

void Floyd() {
    FOR(k, 1, n) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void run_case() {
    cin >> n >> m;

    FOR(i, 1, n) {
        FOR(j, 1, n) {
            d[i][j] = (i == j) ? 0 : 1e9;
        }
    }

    FOR(i, 1, m) {
        int x, y, w;
        cin >> x >> y >> w;

        d[x][y] = d[y][x] = w;
    }

    Floyd();

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        cout << d[x][y] << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}