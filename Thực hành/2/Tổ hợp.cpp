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

string s;
int k;
set<string> ans;

void back_tracking(string res, int start) {
    if (sz(res) == k) {
        ans.insert(res);
        return;
    }
    FOR(i, start, sz(s) - 1) {
        back_tracking(res + s[i], i + 1);
    }
}

void run_case() {
    cin >> s >> k;

    back_tracking("", 0);

    for (string s : ans)
        cout << s << endl;

    ans.clear();
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