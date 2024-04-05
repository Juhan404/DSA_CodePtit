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

    stack<char> st;
    for (char c : s) {
        if (c != ')')
            st.push(c);
        else {
            string temp = "";
            while (st.top() != '(') {
                temp = st.top() + temp;
                st.pop();
            }
            st.pop();

            if (sz(st) != 0 && st.top() == '-') {
                for (char x : temp) {
                    if (x == '+')
                        x = '-';
                    else if (x == '-')
                        x = '+';

                    st.push(x);
                }
            }
            else {
                for (char x : temp)
                    st.push(x);
            }
        }
        debug(st);
    }

    string res = "";
    while (sz(st) != 0) {
        res = st.top() + res;
        st.pop();
    }

    cout << res << endl;
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