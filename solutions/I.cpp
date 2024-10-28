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
  vector<array<int, 3>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v, b, d;
    cin >> u >> v >> b >> d, --u, --v;
    adj[u].push_back({v, b, d});
    adj[v].push_back({u, b, d});
    edges.push_back({b, u, v});
  }
  vector<int> dsu(n), sz(n, 1);
  iota(dsu.begin(), dsu.end(), 0);
  int l;
  sort(edges.rbegin(), edges.rend());
  function<int(int)> find = [&] (int u) {
    return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
  };
  auto unite = [&] (int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      if (sz[u] < sz[v]) {
        swap(u, v);
      }
      dsu[v] = u;
      sz[u] += sz[v];
    }
  };
  for (auto &e : edges) {
    l = e[0];
    unite(e[1], e[2]);
    if (find(S) == find(E)) {
      break;
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
