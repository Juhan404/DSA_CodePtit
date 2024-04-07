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

vector<string> v;

void back_tracking(string s, int index) {
    if (sz(s) == index) {
        v.pb(s);
        return;
    }
    back_tracking(s + "6", index);
    back_tracking(s + "8", index);
}

void run_case() {
    int n;
    cin >> n;

    FOR(i, 1, n) {
        string temp = v[i - 1];
        reverse(temp.begin(), temp.end());
        cout << v[i - 1] << temp << ' ';
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef Juhan404
    freopen("Error.txt", "w", stderr);
#endif

    int T = 1;
    cin >> T;

    FOR(i, 1, 15) {
        back_tracking("", i);
    }

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}