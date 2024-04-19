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

int n, m, vs[1005], check, s[1005];
vector<int> adj[1005];

void DFS(int u) {
    if (check == 0)
        return;

    vs[u] = 1;

    for (int v : adj[u]) {
        if (!vs[v]) {
            if (s[v] == 0)
                s[v] = 1 - s[u];

            DFS(v);
        }
        else if (s[v] == s[u]) {
            check = 0;
            return;
        }
    }
}

void run_case() {
    cin >> n >> m;
    check = 1;

    FOR(i, 1, n) {
        adj[i].clear();
        vs[i] = 0;
        s[i] = 0;
    }

    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    FOR(i, 1, n) {
        memset(vs, 0, sizeof(vs));
        DFS(i);

        if (check == 0)
            break;
    }

    cout << (check ? "YES" : "NO") << endl;
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