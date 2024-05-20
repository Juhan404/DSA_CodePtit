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

int n, m, a[1005][1005], vs[1005][1005];

struct pos {
    int x, y, d;
};

void run_case() {
    cin >> n >> m;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
            vs[i][j] = 0;
        }
    }

    queue<pos> q;
    q.push({1, 1, 0});

    while (sz(q)) {
        pos u = q.front();
        q.pop();

        int i = u.x, j = u.y;

        if (i == n && j == m) {
            cout << u.d << endl;
            return;
        }

        if (i + abs(a[i][j] - a[i + 1][j]) <= n && !vs[i + abs(a[i][j] - a[i + 1][j])][j]) {
            vs[i + abs(a[i][j] - a[i + 1][j])][j] = 1;
            q.push({i + abs(a[i][j] - a[i + 1][j]), j, u.d + 1});
        }

        if (j + abs(a[i][j] - a[i][j + 1]) <= m && !vs[i][j + abs(a[i][j] - a[i][j + 1])]) {
            vs[i][j + abs(a[i][j] - a[i][j + 1])] = 1;
            q.push({i, j + abs(a[i][j] - a[i][j + 1]), u.d + 1});
        }

        if (i + abs(a[i][j] - a[i + 1][j + 1]) <= n && j + abs(a[i][j] - a[i + 1][j + 1]) <= m && !vs[i + abs(a[i][j] - a[i + 1][j + 1])][j + abs(a[i][j] - a[i + 1][j + 1])]) {
            vs[i + abs(a[i][j] - a[i + 1][j + 1])][j + abs(a[i][j] - a[i + 1][j + 1])] = 1;
            q.push({i + abs(a[i][j] - a[i + 1][j + 1]), j + abs(a[i][j] - a[i + 1][j + 1]), u.d + 1});
        }
    }

    cout << -1 << endl;
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