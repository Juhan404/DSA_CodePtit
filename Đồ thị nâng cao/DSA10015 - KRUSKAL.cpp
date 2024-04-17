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

struct E {
    ll u, v, w;
};

int n, m;
int par[105], sz[10005];
vector<E> edges;

void Input() {
    edges.clear();

    cin >> n >> m;

    FOR(i, 1, n) {
        par[i] = i;
        sz[i] = 1;
    }

    FOR(i, 1, m) {
        ll u, v, w;
        cin >> u >> v >> w;

        edges.pb({u, v, w});
    }
}

int Find(int u) {
    if (u == par[u])
        return u;
    else
        return par[u] = Find(par[u]);
}

int Union(int u, int v) {
    int x = Find(u), y = Find(v);

    if (x != y) {
        if (sz[x] > sz[y]) {
            par[y] = x;
            sz[x] += sz[y];
        }
        else {
            par[x] = y;
            sz[y] += sz[x];
        }

        return 1;
    }
    else
        return 0;
}

ll Kruscal() {
    sort(edges.begin(), edges.end(), [](E x, E y) -> bool {
        return x.w < y.w;
    });

    ll res = 0;
    vector<E> MST;

    for (E i : edges) {
        if (sz(MST) > n - 1)
            break;

        if (Union(i.u, i.v)) {
            res += i.w;
            MST.pb(i);
        }
    }

    return res;
}

void run_case() {
    Input();

    cout << Kruscal() << endl;
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