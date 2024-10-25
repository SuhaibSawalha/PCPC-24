#include <bits/stdc++.h>
using namespace std;
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	int S, E;
	cin >> S >> E, --S, --E;
	if (S == E) {
		cout << "0 0";
		return 0;
	}
	vector<vector<array<int, 3>>> adj(n);
	for (int i = 0; i < m; ++i) {
		int u, v, b, d;
		cin >> u >> v >> b >> d, --u, --v;
		adj[u].push_back({v, b, d});
		adj[v].push_back({u, b, d});
	}
	vector<int> vis(n);
	int vid = 0;
	function<void(int, int)> dfs = [&] (int u, int mb) {
		if (vis[u] == vid) {
			return;
		}
		vis[u] = vid;
		for (auto &v : adj[u]) {
			if (v[1] >= mb) {
				dfs(v[0], mb);
			}
		}
	};
	int l = 1, r = 1e9;	 
	while (l < r) {
		int mid = (l + r + 1) / 2;
		++vid;
		dfs(S, mid);
		if (vis[E] == vid) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, S});
	vector<long long> dis(n, LLONG_MAX);
	dis[S] = 0;
	while (pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (u == E) {
			break;
		}
		if (d != dis[u]) {
			continue;
		}
		for (auto &v : adj[u]) {
			if (v[1] >= l && d + v[2] < dis[v[0]]) {
				dis[v[0]] = d + v[2];
				pq.push({dis[v[0]], v[0]});
			}
		}
	}
	cout << l << " " << dis[E];

  return 0;
}
