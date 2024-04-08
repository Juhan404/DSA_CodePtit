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

    int a[n + 1];
    FOR(i, 1, n) {
        cin >> a[i];
    }

    stack<int> st;
    vector<int> big(n + 1);

    ROF(i, n, 1) {
        while (sz(st) && a[st.top()] <= a[i])
            st.pop();

        if (st.empty())
            big[i] = -1;
        else
            big[i] = st.top();

        st.push(i);
    }
    debug(big);

    while (sz(st))
        st.pop();

    vector<int> small(n + 1);
    ROF(i, n, 1) {
        while (sz(st) && a[st.top()] >= a[i])
            st.pop();

        if (st.empty())
            small[i] = -1;
        else
            small[i] = st.top();

        st.push(i);
    }
    debug(small);

    FOR(i, 1, n) {
        if (big[i] == -1 || small[big[i]] == -1)
            cout << -1 << " ";
        else
            cout << a[small[big[i]]] << " ";
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