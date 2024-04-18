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

int n, m, st;
vector<int> adj[1005];
vector<pii> path;
int vs[1005];

void BFS(int u) {
    queue<int> q;

    q.push(u);
    vs[u] = 1;

    while (sz(q)) {
        int x = q.front();
        q.pop();

        for (int i : adj[x]) {
            if (!vs[i]) {
                vs[i] = 1;
                q.push(i);
                path.pb({x, i});
            }
        }
    }
}

void run_case() {
    cin >> n >> m >> st;

    path.clear();
    FOR(i, 1, n) {
        adj[i].clear();
        vs[i] = 0;
    }

    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    BFS(st);

    if (sz(path) == n - 1) {
        for (pii i : path)
            cout << i.fi << ' ' << i.se << endl;
    }
    else
        cout << "-1\n";
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