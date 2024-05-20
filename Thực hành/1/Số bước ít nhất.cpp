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

int a[1005][1005];
int vs[1005][1005];
int n, m, res;

void flood_fill(int i, int j, int cnt) {
    if (i == n && j == m) {
        res = min(res, cnt);
        return;
    }

    if (i < 1 || i > n || j < 1 || j > m || vs[i][j] == 1 || cnt >= res)
        return;

    vs[i][j] = 1;

    flood_fill(i + abs(a[i + 1][j] - a[i][j]), j, cnt + 1);
    flood_fill(i, j + abs(a[i][j + 1] - a[i][j]), cnt + 1);
    flood_fill(i + abs(a[i + 1][j + 1] - a[i][j]), j + abs(a[i + 1][j + 1] - a[i][j]), cnt + 1);

    vs[i][j] = 0;
}

void run_case() {
    cin >> n >> m;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
        }
    }

    res = 1e9;
    flood_fill(1, 1, 0);

    if (res == 1e9)
        cout << -1 << '\n';
    else
        cout << res << '\n';
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