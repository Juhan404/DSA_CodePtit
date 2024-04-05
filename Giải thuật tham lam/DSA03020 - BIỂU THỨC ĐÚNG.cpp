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
    string s;
    cin >> s;

    stack<int> st;
    int ans = 0;

    FOR(i, 0, sz(s) - 1) {
        if (s[i] == '[')
            st.push(i);
        else {
            if (sz(st) != 0)
                st.pop();
            else {
                int j = i;
                while (j < sz(s) && s[j] != '[')
                    ++j;

                swap(s[i], s[j]);
                ans += j - i;

                st.push(i);
            }
        }
    }

    cout << ans << endl;
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