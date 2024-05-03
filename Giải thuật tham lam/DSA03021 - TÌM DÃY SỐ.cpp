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

int n, min_val = 1e9;
vector<int> a, c;

bool check(int x) {
    for (int i : a) {
        if (i / x == i / (x + 1))
            return false;
    }
    return true;
}

void run_case() {
    cin >> n;

    a.resize(n);
    c.resize(n);

    for (int &x : a) {
        cin >> x;
        min_val = min(min_val, x);
    }

    ROF(i, min_val, 1) {
        if (check(i)) {
            FOR(j, 0, n - 1) {
                c[j] = a[j] / (i + 1) + 1;
            }
            break;
        }
    }

    cout << accumulate(c.begin(), c.end(), 0) << endl;
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