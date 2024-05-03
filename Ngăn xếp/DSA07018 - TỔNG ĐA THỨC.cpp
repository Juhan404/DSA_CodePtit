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
map<int, int> mp;

void calc(string s) {
    int i = 0, hs = 0, mu = 0, temp = 0;
    s += ' ';

    while (i < sz(s)) {
        if (isdigit(s[i])) {
            temp *= 10;
            temp += (s[i] - '0');
        }
        else if (s[i] == '*') {
            hs = temp;
            temp = 0;
        }
        else if (s[i] == ' ' && isdigit(s[i - 1])) {
            mu = temp;
            mp[mu] += hs;
            temp = 0;
        }
        ++i;
    }
}

void run_case() {
    mp.clear();

    getline(cin, a);
    getline(cin, b);

    calc(a);
    calc(b);

    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        cout << it->se << "*x^" << it->fi;
        if (it != prev(mp.rend()))
            cout << " + ";
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

    cin.ignore();

    for (int test = 1; test <= T; ++test) {

        run_case();
    }
    return 0;
}