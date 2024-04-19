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

map<int, pii> mp;
vector<string> v;
set<string> se;
string s;
int n, cnt = 1;

void back_tracking(string s) {
    if (sz(s) == cnt) {
        v.pb(s);
        return;
    }
    back_tracking(s + '0');
    back_tracking(s + '1');
}

string remove_brackets(string np) {
    vector<int> ers(n + 1, 1);

    FOR(i, 1, cnt) {
        if (np[i] == '0')
            ers[mp[i].fi] = ers[mp[i].se] = 0;
    }

    string res = "";
    FOR(i, 1, n) {
        if (ers[i] == 1)
            res += s[i];
    }
    return res;
}

void run_case() {
    cin >> s;

    n = sz(s);
    s = "!" + s;

    stack<pii> st;

    FOR(i, 1, n) {
        if (s[i] == '(') {
            mp[cnt].fi = i;
            st.push({cnt, i});
            ++cnt;
        }
        else if (s[i] == ')') {
            mp[st.top().fi].se = i;
            st.pop();
        }
    }
    --cnt;

    back_tracking("");
    v.ppb();

    for (string x : v)
        se.insert(remove_brackets('!' + x));

    for (string s : se)
        cout << s << endl;
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