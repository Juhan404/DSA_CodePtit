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

int v, e;
vector<int> near[1005];
int color[1005];

void Reset() {
    FOR(i, 1, v) {
        near[i].clear();
        color[i] = 0;
    }
}

void Input() {
    cin >> v >> e;
    FOR(i, 1, e) {
        int x, y;
        cin >> x >> y;

        near[x].pb(y);
    }
}

bool Has_cycle(int u) {
    color[u] = 1;

    for (int x : near[u]) {
        if (color[x] == 1)
            return true;
        else if (color[x] == 0 && Has_cycle(x))
            return true;
    }

    color[u] = 2;
    return false;
}

void run_case() {
    Reset();
    Input();

    FOR(i, 1, v) {
        if (color[i] == 0 && Has_cycle(i)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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