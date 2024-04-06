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

void Tower_of_HaNoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << A << " -> " << C << endl;
        return;
    }

    Tower_of_HaNoi(n - 1, A, C, B);
    Tower_of_HaNoi(1, A, B, C);
    Tower_of_HaNoi(n - 1, B, A, C);
}

void run_case() {
    int n;
    cin >> n;

    Tower_of_HaNoi(n, 'A', 'B', 'C');
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