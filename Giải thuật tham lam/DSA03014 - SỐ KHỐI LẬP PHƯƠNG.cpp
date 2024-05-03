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

bool check(string a, string b) {
    int j = 0;
    FOR(i, 0, sz(a) - 1) {
        if (a[i] == b[j])
            j++;
    }
    return (j == sz(b));
}

void run_case() {
    ll n;
    cin >> n;

    ll max_val = cbrt(n), val = 0;

    ROF(i, max_val, 1) {
        val = i * i * i;
        if (check(to_string(n), to_string(val))) {
            cout << val << endl;
            return;
        }
    }

    cout << -1 << endl;
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