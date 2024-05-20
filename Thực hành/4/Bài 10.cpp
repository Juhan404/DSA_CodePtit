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

int n, m, st, en, cha[1005];
string s;
vector <int> ke[1005];
bool visited[1005];

void nhap() {
	memset(visited, false, sizeof(visited));
	FOR(i, 1, n) ke[i].clear();

	cin >> n >> m >> st >> en;

	FOR(i, 1, m) {
		int x, y;
		cin >> x >> y;

		ke[x].pb(y);
	}
}

void BFS(int u) {
	queue <int> q;

	q.push(u);
	visited[u] = true;
	cha[u] = u;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int k : ke[x]) {
			if (!visited[k]) {
				cha[k] = x;
				q.push(k);
				visited[k] = true;
			}
		}
	}
}

void run_case() {
	nhap();

	BFS(st);

	if (!visited[en]) {
		cout << - 1 << endl;
		return;
	}

	vector <int> road;

	while (en != st) {
		road.pb(en);
		en = cha[en];
	}
	road.pb(st);
	reverse(road.begin(), road.end());

	for (int x : road) cout << x << ' ';
	cout << endl;
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);

#ifdef Juhan404
	freopen("Error.txt", "w", stderr);
#endif

	int test = 1;
	cin >> test;

	for (int tc = 1; tc <= test; tc++) {
		// cout << "Test #" << tc << ": ";
		run_case();
	}
	return 0;
}