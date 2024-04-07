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

int n;

void back_tracking(int index, string s, int cnt_2, int cnt_3, int cnt_5, int cnt_7) {
    if (sz(s) == index) {
        if (cnt_2 && cnt_3 && cnt_5 && cnt_7 && (s.back() - '0') & 1)
            cout << s << endl;

        return;
    }
    back_tracking(index, s + "2", cnt_2 + 1, cnt_3, cnt_5, cnt_7);
    back_tracking(index, s + "3", cnt_2, cnt_3 + 1, cnt_5, cnt_7);
    back_tracking(index, s + "5", cnt_2, cnt_3, cnt_5 + 1, cnt_7);
    back_tracking(index, s + "7", cnt_2, cnt_3, cnt_5, cnt_7 + 1);
}

void run_case() {
    cin >> n;

    FOR(i, 4, n) {
        back_tracking(i, "", 0, 0, 0, 0);
    }
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