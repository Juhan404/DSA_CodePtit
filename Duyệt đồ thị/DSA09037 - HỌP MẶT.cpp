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

int k, n, m;
int vs[1005], pos[105], cnt[1005];
vector<int> adj[1005];

void Input() {
    cin >> k >> n >> m;

    FOR(i, 1, k) {
        cin >> pos[i];
    }

    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
    }
}

void DFS(int u) {
    vs[u] = 1;
    cnt[u]++;

    for (int v : adj[u]) {
        if (!vs[v])
            DFS(v);
    }
}

void run_case() {
    Input();

    FOR(i, 1, k) {
        memset(vs, 0, sizeof vs);
        DFS(pos[i]);
    }

    int res = 0;

    FOR(i, 1, n) {
        if (cnt[i] == k)
            ++res;
    }

    cout << res << endl;
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