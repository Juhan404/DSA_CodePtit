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

int n, k, res = 0, s = 0;
vector<int> a;

void back_tracking(int index, int cnt) {
    if (cnt == k) {
        res += (index == n);
        return;
    }
    FOR(i, index + 1, n) {
        if (a[i] - a[index] == s)
            back_tracking(i, cnt + 1);
    }
}

void run_case() {
    cin >> n >> k;

    a.resize(n + 1);

    FOR(i, 1, n) {
        cin >> a[i];
        s += a[i];
        a[i] = s;
    }

    if (s % k != 0) {
        cout << 0 << endl;
        return;
    }

    s /= k;
    back_tracking(0, 0);

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