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

int n;
string a[11], v[11];
int x[11];
int res = 1e9;

void back_tracking(int index, int cnt) {
    if (index > n) {
        res = min(res, cnt);
        return;
    }

    FOR(i, 1, n) {
        if (x[i] == 0) {
            x[i] = 1;
            v[index] = a[i];

            int mp[300] = {}, dem = 0;

            for (char c : v[index])
                mp[c]++;
            for (char c : v[index - 1])
                mp[c]++;

            FOR(i, 'A', 'Z') {
                if (mp[i] == 2)
                    ++dem;
            }

            if (cnt + dem < res)
                back_tracking(index + 1, cnt + dem);

            x[i] = 0;
        }
    }
}

void run_case() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
    }

    back_tracking(1, 0);

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