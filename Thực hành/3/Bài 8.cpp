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

int n, res, sum, hang[10], xuoi[10], nguoc[10], a[10][10];

void back_tracking(int i) {
    FOR(j, 1, 8) {
        if (!hang[j] && !xuoi[i - j + 8] && !nguoc[i + j - 1]) {
            hang[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 1;
            sum += a[i][j];

            if (i == 8)
                res = max(res, sum);
            else
                back_tracking(i + 1);

            sum -= a[i][j];
            hang[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 0;
        }
    }
}

void run_case() {
    res = -1, sum = 0;

    FOR(i, 1, 8) {
        FOR(j, 1, 8) {
            cin >> a[i][j];
        }
    }

    back_tracking(1);

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
        cout << "Test " << test << ": ";
        run_case();
    }
    return 0;
}