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

string a, b;
pii st, en;
int res, vs[8][8];

void DFS(pii pos, int cnt) {
    if (cnt >= res)
        return;

    if (pos == en) {
        res = min(res, cnt);
        return;
    }

    if (pos.fi < 0 || pos.fi >= 8 || pos.se < 0 || pos.se >= 8 || vs[pos.fi][pos.se])
        return;

    vs[pos.fi][pos.se] = 1;

    DFS({pos.fi - 2, pos.se - 1}, cnt + 1);
    DFS({pos.fi - 2, pos.se + 1}, cnt + 1);
    DFS({pos.fi - 1, pos.se - 2}, cnt + 1);
    DFS({pos.fi - 1, pos.se + 2}, cnt + 1);
    DFS({pos.fi + 1, pos.se - 2}, cnt + 1);
    DFS({pos.fi + 1, pos.se + 2}, cnt + 1);
    DFS({pos.fi + 2, pos.se - 1}, cnt + 1);
    DFS({pos.fi + 2, pos.se + 1}, cnt + 1);

    vs[pos.fi][pos.se] = 0;
}

void run_case() {
    memset(vs, 0, sizeof(vs));
    cin >> a >> b;

    st = {a[0] - 'a', a[1] - '1'};
    en = {b[0] - 'a', b[1] - '1'};
    res = 1e9;

    DFS(st, 0);

    cout << res << endl;
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