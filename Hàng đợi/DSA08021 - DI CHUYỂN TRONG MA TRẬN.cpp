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

int n, m;
int a[1005][1005], vs[1005][1005], f[1005][1005];

void BFS(int i, int j) {
    queue<pii> q;

    q.push({i, j});
    vs[i][j] = 1;
    f[i][j] = 0;

    while (sz(q)) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        if (x == n && y == m) {
            cout << f[x][y] << endl;
            return;
        }

        if (x + a[x][y] <= n && vs[x + a[x][y]][y] == 0) {
            vs[x + a[x][y]][y] = 1;
            f[x + a[x][y]][y] = f[x][y] + 1;

            q.push({x + a[x][y], y});
        }

        if (y + a[x][y] <= m && vs[x][y + a[x][y]] == 0) {
            vs[x][y + a[x][y]] = 1;
            f[x][y + a[x][y]] = f[x][y] + 1;

            q.push({x, y + a[x][y]});
        }
    }

    cout << -1 << endl;
}

void run_case() {
    cin >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];

            f[i][j] = 0;
            vs[i][j] = 0;
        }
    }

    BFS(1, 1);
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