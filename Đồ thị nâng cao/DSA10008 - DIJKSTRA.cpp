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
vector<pii> adj[1005];

void Dijkstra(int u) {
    vector<int> d(n + 1, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, u});
    d[u] = 0;

    while (sz(pq)) {
        int dist = pq.top().fi, v = pq.top().se;
        pq.pop();

        if (dist > d[v])
            continue;

        for (pii x : adj[v]) {
            int a = x.fi, b = x.se;
            if (d[a] > d[v] + b) {
                d[a] = d[v] + b;
                pq.push({d[a], a});
            }
        }
    }

    FOR(i, 1, n) {
        cout << d[i] << ' ';
    }
    cout << endl;
}

void run_case() {
    cin >> n >> m >> st;

    FOR(i, 1, n) {
        adj[i].clear();
    }

    FOR(i, 1, m) {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }

    Dijkstra(st);
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