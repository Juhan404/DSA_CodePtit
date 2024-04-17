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

int s, t;
int vs[10005], f[10005];

void BFS(int u) {
    queue<int> q;

    q.push(u);
    vs[u] = 1;
    f[u] = 0;

    while (sz(q)) {
        int x = q.front();
        q.pop();

        if (x - 1 == t || x << 1 == t) {
            cout << f[x] + 1 << endl;
            return;
        }

        if (!vs[x - 1]) {
            vs[x - 1] = 1;
            f[x - 1] = f[x] + 1;

            q.push(x - 1);
        }

        if (!vs[x << 1] && (x << 1) <= 10000) {
            vs[x << 1] = 1;
            f[x << 1] = f[x] + 1;

            q.push(x << 1);
        }
    }
}

void run_case() {
    cin >> s >> t;

    memset(vs, 0, sizeof(vs));
    memset(f, 0, sizeof(f));

    BFS(s);
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