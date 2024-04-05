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

vector<int> near[15];
int vs[15], v, e, check;

void Reset() {
    check = 0;
    FOR(i, 1, v) {
        near[i].clear();
        vs[i] = 0;
    }
}

void Input() {
    cin >> v >> e;
    FOR(i, 1, e) {
        int x, y;
        cin >> x >> y;

        near[x].pb(y);
        near[y].pb(x);
    }
}

void DFS(int u, int cnt) {
    if (cnt == v)
        check = 1;

    if (check == 1)
        return;

    vs[u] = 1;

    for (int x : near[u]) {
        if (!vs[x]) {
            vs[x] = 1;

            DFS(x, cnt + 1);

            vs[x] = 0;
        }
    }
}

void run_case() {
    Reset();
    Input();

    FOR(i, 1, v) {
        memset(vs, 0, sizeof(vs));
        DFS(i, 1);
        if (check == 1)
            break;
    }

    cout << check << endl;
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