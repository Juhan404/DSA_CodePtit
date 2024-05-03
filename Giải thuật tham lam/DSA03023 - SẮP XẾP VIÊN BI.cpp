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

int n, cnt[3], res = 0;
string s;

void Find(int l, int r, int index, char c) {
    FOR(i, l, r) {
        if (s[i] == c) {
            swap(s[i], s[index]);
            ++res;
            return;
        }
    }
}

void run_case() {
    cin >> n >> s;

    for (char c : s) {
        if (c == 'X')
            ++cnt[0];
        else if (c == 'T')
            ++cnt[1];
        else
            ++cnt[2];
    }

    FOR(i, 0, cnt[0] - 1) {
        if (s[i] == 'T')
            Find(cnt[0], n - 1, i, 'X');
        else if (s[i] == 'D') {
            ROF(j, n - 1, cnt[0]) {
                if (s[j] == 'X') {
                    swap(s[j], s[i]);
                    ++res;
                    break;
                }
            }
        }
    }

    FOR(i, cnt[0], cnt[0] + cnt[1] - 1) {
        if (s[i] == 'D')
            Find(cnt[0] + cnt[1], n - 1, i, 'T');
    }

    cout << res << endl;
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