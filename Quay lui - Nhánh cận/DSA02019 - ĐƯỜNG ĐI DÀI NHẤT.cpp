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

int n, m, res;
vector<int> adj[25];
int vs[25][25];

void DFS(int u, int cnt) {
    res = max(res, cnt);
    for (auto v : adj[u]) {
        if (!vs[u][v]) {
            vs[u][v] = vs[v][u] = 1;
            DFS(v, cnt + 1);
            vs[u][v] = vs[v][u] = 0;
        }
    }
}

void run_case() {
    cin >> n >> m;

    FOR(i, 1, n) {
        adj[i].clear();
    }
    res = -1;

    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        ++x, ++y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    FOR(i, 1, n) {
        DFS(i, 0);
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