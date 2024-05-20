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

pii st, en;
int res = 1e9, vs[10][10];
int X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(pii pos, int cnt) {
    if (cnt > res)
        return;

    if (pos == en) {
        res = min(res, cnt);
        return;
    }

    vs[pos.fi][pos.se] = 1;

    FOR(i, 0, 7) {
        int x = pos.fi + X[i];
        int y = pos.se + Y[i];

        if (!vs[x][y] && x >= 1 && x <= 8 && y >= 1 && y <= 8)
            DFS({x, y}, cnt + 1);
    }

    vs[pos.fi][pos.se] = 0;
}

void run_case() {
    cin >> st.fi >> st.se >> en.fi >> en.se;

    DFS(st, 0);

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