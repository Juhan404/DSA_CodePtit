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

int n, x[20], k;

void back_tracking(int i) {
    if (i == k + 1) {
        FOR(j, 1, k) {
            cout << x[j] << ' ';
        }
        cout << endl;
        return;
    }
    FOR(j, 1, n) {
        if (j >= x[i - 1]) {
            x[i] = j;
            back_tracking(i + 1);
        }
    }
}

void run_case() {
    cin >> n >> k;

    back_tracking(1);
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