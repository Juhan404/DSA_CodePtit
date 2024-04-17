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

    map<int, int> mp;
    int a[n + 1];

    FOR(i, 1, n) {
        cin >> a[i];
        mp[a[i]]++;
    }

    int f[n + 1];
    stack<int> st;

    ROF(i, n, 1) {
        while (sz(st) && mp[a[st.top()]] <= mp[a[i]])
            st.pop();

        if (st.empty())
            f[i] = -1;
        else
            f[i] = st.top();

        st.push(i);
    }

    FOR(i, 1, n) {
        if (f[i] == -1)
            cout << f[i] << ' ';
        else
            cout << a[f[i]] << ' ';
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