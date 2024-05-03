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

string a, b;

string Changed(string s, int n) {
    s = '!' + s;

    stack<int> st;
    FOR(i, 1, n) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            if (st.top() != 1 && s[st.top() - 1] == '-') {
                FOR(j, st.top(), i) {
                    if (s[j] == '+')
                        s[j] = '-';
                    else if (s[j] == '-')
                        s[j] = '+';
                }
            }
            st.pop();
        }
    }

    string res = "";
    FOR(i, 1, n) {
        if (s[i] != '(' && s[i] != ')')
            res += s[i];
    }

    return res;
}

void run_case() {
    cin >> a >> b;

    cout << (Changed(a, sz(a)) == Changed(b, sz(b)) ? "YES" : "NO") << endl;
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