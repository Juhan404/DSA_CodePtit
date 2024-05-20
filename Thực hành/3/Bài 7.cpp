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

ll n, s, a[50], res = 1e9;

void back_tracking(ll i, ll sum, ll cnt) {
    if (cnt > res || sum > s)
        return;

    if (i == n) {
        if (sum == s)
            res = cnt;
        return;
    }

    back_tracking(i + 1, sum, cnt);
    back_tracking(i + 1, sum + a[i], cnt + 1);
}

void run_case() {
    cin >> n >> s;
    FOR(i, 1, n) {
        cin >> a[i];
    }

    back_tracking(1, 0, 0);

    if (res == 1e9)
        cout << -1;
    else
        cout << res;
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