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

string s;
set<string> se;
int max_sz;

bool check(string s) {
    if (sz(s) < 2)
        return false;

    stack<char> st;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

void back_tracking(string s, int index) {
    if (sz(s) < max_sz) {
        return;
    }

    if (check(s)) {
        if (sz(s) > max_sz) {
            max_sz = sz(s);
            se.clear(); // neu tim dc bieu thuc dung dai hon thi se xoa het cac bieu thuc truoc do
        }
        se.insert(s);
        return;
    }

    FOR(i, index, sz(s) - 1) {
        if (s[i] == '(' || s[i] == ')') {
            string tmp = s;
            tmp.erase(i, 1);
            back_tracking(tmp, i);
        }
    }
}

void run_case() {
    cin >> s;

    max_sz = 0;
    se.clear();

    back_tracking(s, 0);

    if (sz(se) == 0) {
        cout << "-1\n";
        return;
    }

    for (string x : se) {
        cout << x << ' ';
    }
    cout << '\n';
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