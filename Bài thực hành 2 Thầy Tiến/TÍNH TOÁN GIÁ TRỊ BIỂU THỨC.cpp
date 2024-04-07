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

ll postfix_calc() {
    stack<string> st;

    for (auto &s : v) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            ll b = stoll(st.top());
            st.pop();

            ll a = stoll(st.top());
            st.pop();

            if (s == "+")
                st.push(to_string(a + b));
            else if (s == "-")
                st.push(to_string(a - b));
            else if (s == "*")
                st.push(to_string(a * b));
            else if (s == "/")
                st.push(to_string(a / b));
        }
        else {
            st.push(s);
        }
    }

    return stoll(st.top());
}

ll prefix_calc() {
    reverse(v.begin(), v.end());

    stack<string> st;

    for (auto &s : v) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            ll a = stoll(st.top());
            st.pop();

            ll b = stoll(st.top());
            st.pop();

            if (s == "+")
                st.push(to_string(a + b));
            else if (s == "-")
                st.push(to_string(a - b));
            else if (s == "*")
                st.push(to_string(a * b));
            else if (s == "/")
                st.push(to_string(a / b));
        }
        else {
            st.push(s);
        }
    }

    return stoll(st.top());
}

void run_case() {
    int n;
    cin >> n;

    v.resize(n);
    for (auto &s : v)
        cin >> s;

    if (v.back() != "-" && v.back() != "+" && v.back() != "*" && v.back() != "/")
        cout << prefix_calc() << endl;
    else
        cout << postfix_calc() << endl;
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