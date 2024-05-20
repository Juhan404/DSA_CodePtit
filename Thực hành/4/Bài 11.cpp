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
vector<int> adj[1005], path;
int vs[1005], par[1005];

void Input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }
}

void DFS(int u) {
    vs[u] = 1;
    for (int v : adj[u]) {
        if (!vs[v]) {
            par[v] = u;
            DFS(v);
        }
    }
}

void BFS(int u) {
    queue<int> q;

    q.push(u);
    vs[u] = 1;

    while (sz(q)) {
        int v = q.front();
        q.pop();

        for (int x : adj[v]) {
            if (!vs[x]) {
                vs[x] = 1;
                par[x] = v;

                q.push(x);
            }
        }
    }
}

void Trace(int st, int en) {
    while (en != st) {
        path.pb(en);
        en = par[en];
    }
    path.pb(st);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << ' ';
    cout << endl;
}

void run_case() {
    Input();

    FOR(i, 2, n) {
        memset(vs, 0, sizeof(vs));
        path.clear();
        par[1] = 1;

        DFS(1);

        if (!vs[i])
            cout << -1 << endl;
        else
            Trace(1, i);

        memset(vs, 0, sizeof(vs));
        path.clear();
        par[i] = i;

        BFS(i);

        if (!vs[1])
            cout << -1 << endl;
        else
            Trace(i, 1);
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