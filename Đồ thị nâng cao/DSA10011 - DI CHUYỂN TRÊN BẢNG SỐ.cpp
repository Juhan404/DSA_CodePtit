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

int n, m, d[505][505], a[505][505], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void Dijkstra() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    d[1][1] = a[1][1];
    pq.push({a[1][1], {1, 1}});

    while (sz(pq)) {
        pair<int, pii> x = pq.top();
        pq.pop();

        int dis = x.fi, i = x.se.fi, j = x.se.se;

        if (dis > d[i][j])
            continue;

        FOR(k, 0, 3) {
            int ni = i + dx[k], nj = j + dy[k];

            if (ni < 1 || nj < 1 || ni > n || nj > m)
                continue;

            if (d[ni][nj] > d[i][j] + a[ni][nj]) {
                d[ni][nj] = d[i][j] + a[ni][nj];
                pq.push({d[ni][nj], {ni, nj}});
            }
        }
    }

    cout << d[n][m] << endl;
}

void run_case() {
    cin >> n >> m;

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cin >> a[i][j];
            d[i][j] = 1e9;
        }
    }

    Dijkstra();
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