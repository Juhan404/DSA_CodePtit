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

void back_tracking(int i, int n, string s) {
    if (sz(s) == n) {
        v.pb(s);
        return;
    }

    back_tracking(i + 1, n, s + '0');
    back_tracking(i + 1, n, s + '1');
}

void run_case() {
    int n;
    cin >> n;

    for (string s : v) {
        if (sz(s) * 2 > n) {
            break;
        }
        else {
            string temp = s;
            reverse(temp.begin(), temp.end());
            cout << s + temp << ' ';
        }
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
        back_tracking(1, i, "");
    }

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}