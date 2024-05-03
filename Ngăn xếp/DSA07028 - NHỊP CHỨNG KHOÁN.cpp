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

void run_case() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    FOR(i, 1, n) {
        cin >> a[i];
    }

    vector<int> f(n + 1, 1);
    stack<int> st;

    FOR(i, 1, n) {
        while (sz(st) && a[i] >= a[st.top()]) {
            f[i] += f[st.top()];
            st.pop();
        }
        st.push(i);
    }

    FOR(i, 1, n) {
        cout << f[i] << ' ';
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

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}