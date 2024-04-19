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

void run_case() {
    int n;
    cin >> n;

    queue<pii> q;
    q.push({n, 0});
    unordered_map<int, int> vs;
    vs[n] = 1;

    while (sz(q)) {
        pii u = q.front();
        q.pop();

        if (u.fi == 2) {
            cout << u.se + 1 << endl;
            return;
        }

        q.push({u.fi - 1, u.se + 1});

        FOR(i, 2, sqrt(u.fi)) {
            if (u.fi % i == 0) {
                if (vs[u.fi / i] == 0) {
                    q.push({u.fi / i, u.se + 1});
                    vs[u.fi / i] = 1;
                }
            }
        }
    }
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