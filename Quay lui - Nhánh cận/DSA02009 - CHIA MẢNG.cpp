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

int n, k, a[25], sum, check, x[25];

void back_tracking(int s, int cnt) {
    if (check == 1)
        return;

    if (cnt == k) {
        check = 1;
        return;
    }

    FOR(i, 1, n) {
        if (x[i] == 0) {
            x[i] = 1;

            if (s == sum)
                back_tracking(0, cnt + 1);
            else if (s < sum)
                back_tracking(s + a[i], cnt);
        }
        x[i] = 0;
    }
}

void run_case() {
    cin >> n >> k;
    sum = 0;

    FOR(i, 1, n) {
        cin >> a[i];
        sum += a[i];
        x[i] = 0;
    }

    if (sum % k != 0) {
        cout << "0\n";
        return;
    }

    sum /= k;
    check = 0;
    back_tracking(0, 0);

    cout << (check == 1) << endl;
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