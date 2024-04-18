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

ll n, sum[200005], res[200005];
vector<int> adj[200005];

void DFS(int u) {
    for (int v : adj[u]) {
        DFS(v);

        sum[u] += sum[v] + 1;
        res[u] += res[v];
    }
    res[u] += sum[u];
}

void run_case() {
    cin >> n;
    FOR(i, 1, n) {
        res[i] = 1;

        if (i == 1)
            continue;

        int x;
        cin >> x;

        adj[x].pb(i);
    }

    DFS(1);

    FOR(i, 1, n) {
        cout << res[i] << ' ';
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