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

void back_tracking(string s, int A, int B, int C) {
    if (sz(s) <= n) {
        if (A && B && C && A <= B && B <= C)
            v.pb(s);
        if (sz(s) == n)
            return;
    }
    back_tracking(s + 'A', A + 1, B, C);
    back_tracking(s + 'B', A, B + 1, C);
    back_tracking(s + 'C', A, B, C + 1);
}

void run_case() {
    cin >> n;

    back_tracking("", 0, 0, 0);

    sort(v.begin(), v.end(), [](string a, string b) {
        return sz(a) != sz(b) ? sz(a) < sz(b) : a < b;
    });

    for (string s : v)
        cout << s << endl;
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