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

int n, k, res = 1e9, a[10];
bool x[10];
vector<string> v;

void update() {
    vector<string> temp = v;

    FOR(j, 0, k - 1) {
        FOR(i, 0, n - 1) {
            temp[i][j] = v[i][a[j] - 1];
        }
    }

    sort(temp.begin(), temp.end());

    res = min(res, stoi(temp[n - 1]) - stoi(temp[0]));
}

void back_tracking(int i) {
    FOR(j, 1, k) {
        if (!x[j]) {
            x[j] = true;
            a[i] = j;

            if (i == k - 1)
                update();
            else
                back_tracking(i + 1);

            x[j] = false;
        }
    }
}

void run_case() {
    cin >> n >> k;
    v.resize(n);

    for (string &s : v)
        cin >> s;

    back_tracking(0);

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