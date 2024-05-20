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
vector<string> v;

void back_tracking(string s) {
    if (sz(s) == n) {
        v.pb(s);
        return;
    }
    FOR(i, 1, n) {
        back_tracking(s + to_string(i));
    }
}

void run_case() {
    cin >> n;

    back_tracking("");

    string ans = "";
    FOR(i, 1, n) {
        ans += (char)('A' + i - 1);
    }

    do {
        for (string s : v) {
            cout << ans << s << endl;
        }
    } while (next_permutation(ans.begin(), ans.end()));
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