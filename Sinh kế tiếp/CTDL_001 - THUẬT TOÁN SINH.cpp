#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (auto i = (a); i >= (b); --i)
#define sz(x) (int) (x).size()
#define pb push_back
#define endl '\n'
#define fi first
#define se second

#ifdef Juhan404
#include "debug.h"
#else
#define debug(...)
#endif

using ll = long long;
using pii = pair <int, int>;

const ll INF = 1e9 + 69;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int n, a[1005];
bool final = false;

bool check() {
	FOR(i, 1, n / 2) {
		if (a[i] != a[n - i + 1])
			return false;
	}
	return true;
}

void sinh() {
	int i = n;
	while (i >= 1 && a[i]) --i;
	if (i == 0) final = true;
	else {
		a[i] = 1;
		FOR(j, i + 1, n) a[j] = 0;
	}
}

void run_case() {
	cin >> n;
	while (!final) {
		if (check()) {
			FOR(i, 1, n) {
				cout << a[i] << ' ';
			}
			cout << endl;
		}
		sinh();
	}
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);

#ifdef Juhan404
	freopen("Error.txt", "w", stderr);
#endif

	int test = 1;
	// cin >> test;

	for (int tc = 1; tc <= test; tc++) {
		// cout << "Test #" << tc << ": ";
		run_case();
	}
	return 0;
}