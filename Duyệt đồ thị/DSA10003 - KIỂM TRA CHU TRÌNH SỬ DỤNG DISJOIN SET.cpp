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
int sz[1005], par[1005];

int Find(int u) {
    if (u == par[u])
        return par[u];
    else
        return par[u] = Find(par[u]);
}

int Union(int u, int v) {
    u = Find(u), v = Find(v);

    if (u == v)
        return 1;

    if (sz[v] > sz[u])
        swap(u, v);

    par[v] = u;
    sz[u] += v;

    return 0;
}

void run_case() {
    cin >> n >> m;

    FOR(i, 1, n) {
        par[i] = i;
        sz[i] = 1;
    }

    int check = 0;

    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;

        if (Union(x, y))
            check = 1;
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