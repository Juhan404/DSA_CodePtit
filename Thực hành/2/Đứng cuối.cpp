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

int n, x[15];
string last;
vector<string> v, temp;
vector<vector<string>> res;

void back_tracking(int index) {
    if (index == n + 1) {
        res.pb(temp);
        return;
    }
    FOR(i, 1, n) {
        if (x[i] == 0) {
            x[i] = 1;
            temp.pb(v[i]);

            back_tracking(index + 1);

            temp.ppb();
            x[i] = 0;
        }
    }
}

void run_case() {
    cin >> n;

    v.resize(n + 1);

    FOR(i, 1, n) {
        cin >> v[i];
    }
    cin >> last;

    sort(v.begin() + 1, v.end());

    back_tracking(1);

    for (auto i : res) {
        if (i.back() == last) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
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