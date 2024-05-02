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

vector<int> v;
bool vs[6];

void back_tracking(string s) {
    v.pb(stoi(s));
    FOR(i, 0, 5) {
        if (!vs[i]) {
            vs[i] = 1;
            back_tracking(s + to_string(i));
            vs[i] = 0;
        }
    }
}

void Prepare() {
    v.pb(0);
    FOR(i, 1, 5) {
        if (!vs[i]) {
            vs[i] = 1;
            back_tracking(to_string(i));
            vs[i] = 0;
        }
    }
    sort(v.begin(), v.end());
}

void run_case() {
    int l, r;
    cin >> l >> r;

    l = lower_bound(v.begin(), v.end(), l) - v.begin();
    r = upper_bound(v.begin(), v.end(), r) - v.begin();

    cout << r - l << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;
    cin >> T;

    Prepare();

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}