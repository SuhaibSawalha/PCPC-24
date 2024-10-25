#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, prime = 101, N = 1e5 + 5;
int add (int a, int b) {
	return (a + b) % mod;
}
int mul (int a, int b) {
	return (a * 1LL * b) % mod;
}
int sub (int a, int b) {
	return ((a - b) % mod + mod) % mod;
}

int fastpow (int v, int p) {
	int res = 1;
	while (p) {
		if (p % 2) {
			res = mul(res, v);
		}
		v = mul(v, v);
		p /= 2;
	}
	return res;
}
int Inv (int n) {
	return fastpow(n, mod - 2);
}

int pw[N + 1], pwInv[N + 1];

struct BinaryLifting {
	int n, exp = 20;
	vector<int> depth;
	vector<vector<int>> T;
	BinaryLifting (vector<vector<int>> &adj) {
		n = adj.size();
		T = vector<vector<int>>(n, vector<int>(exp));
		depth.resize(n);
		dfs(adj);
		for (int i = 1; i < exp; ++i) {
			for (int u = 0; u < n; ++u) {
				if (~T[u][i - 1]) {
					T[u][i] = T[T[u][i - 1]][i - 1];
				}
			}
		}
	}

	void dfs (vector<vector<int>> &adj, int u = 0, int p = -1, int d = 0) {
		T[u][0] = p;
		depth[u] = d++;
		for (int v : adj[u]) {
			if (v != p) {
				dfs(adj, v, u, d);
			}
		}
	}
	int LCA (int u, int v) {
		if (depth[u] < depth[v]) {
			swap(u, v);
		}
		int dif = depth[u] - depth[v];
		for (int i = 0; i < exp; ++i) {
			if (dif >> i & 1) {
				u = T[u][i];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = exp - 1; ~i; --i) {
			if (T[u][i] != T[v][i]) {
				u = T[u][i];
				v = T[v][i];
			}
		}
		return T[u][0];
	}

	int distance (int u, int v) {
		return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
	}

	int jump (int u, int d) {
		for (int i = 0; i < exp; ++i) {
			if (d >> i & 1) {
				u = T[u][i];
			}
		}
		return u;
	}
};
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pw[0] = 1, pwInv[0] = 1;
  for (int i = 1; i <= N; ++i) {
  	pw[i] = mul(pw[i - 1], prime);
  	pwInv[i] = Inv(pw[i]);
  }

  int tt;
  cin >> tt;
  while (tt--) {
  	int n;
  	string s;
  	cin >> n >> s;
  	vector<vector<int>> adj(n);
  	for (int i = 1; i < n; ++i) {
  		int u, v;
  		cin >> u >> v, --u, --v;
  		adj[u].push_back(v);
  		adj[v].push_back(u);
  	}
  	vector<int> S(n), E(n);
  	vector<int> p(2 * n), pr(2 * n);
  	int dfst = 0;
  	function<void(int, int, int)> dfs = [&] (int u, int par, int d) {
  		S[u] = dfst++;
  		p[S[u]] = mul(s[u], pw[d]);
  		pr[S[u]] = mul(s[u], pw[N - d]);
  		for (int v : adj[u]) {
  			if (v != par) {
  				dfs(v, u, d + 1);
  			}
  		}
  		E[u] = dfst++;
  		p[E[u]] = mul(s[u], sub(0, pw[d]));
  		pr[E[u]] = mul(s[u], sub(0, pw[N - d]));
  	};
  	dfs(0, -1, 0);
  	for (int i = 1; i < 2 * n; ++i) {
  		p[i] = add(p[i], p[i - 1]);
  		pr[i] = add(pr[i], pr[i - 1]);
  	}
  	BinaryLifting BL(adj);
  	auto getIndex = [&] (int a, int b, int mid) {
  		int l = BL.LCA(a, b);
  		int d = BL.distance(a, l);
  		if (d >= mid) {
  			return BL.jump(a, mid);
  		}
  		d = BL.distance(a, b);
  		return BL.jump(b, d - mid);
  	};
  	auto getHash = [&] (int a, int b, int mid) {
			b = getIndex(a, b, mid);
			int l = BL.LCA(a, b);
			int v = sub(pr[S[a]], S[l] == 0 ? 0 : pr[S[l] - 1]);
			v = mul(v, pwInv[N - BL.depth[a]]);
			if (l == b) {
				return v;
			}
			int v2 = sub(p[S[b]], p[S[l]]);
			v2 = mul(v2, pwInv[BL.depth[l] + 1]);
			v2 = mul(v2, pw[BL.distance(a, l) + 1]);
			return add(v, v2);
  	};
  	auto getChar = [&] (int a, int b, int mid) {
  		return s[getIndex(a, b, mid)];
  	};
  	int q;
  	cin >> q;
  	while (q--) {
  		int a, b, c, d;
  		cin >> a >> b >> c >> d, --a, --b, --c, --d;
  		int d1 = BL.distance(a, b);
  		int d2 = BL.distance(c, d);
  		int l = 0, r = min(d1, d2);
  		while (l < r) {
  			int mid = (l + r) / 2;
  			int v1 = getHash(a, b, mid);
  			int v2 = getHash(c, d, mid);
  			if (v1 != v2) {
  				r = mid;
  			}
  			else {
  				l = mid + 1;
  			}
  		}
  		if (getHash(a, b, l) == getHash(c, d, l)) {
  			cout << (d1 < d2 ? 2 : d1 == d2 ? 0 : 1) << "\n";
  		}
  		else {
  			int c1 = getChar(a, b, l);
  			int c2 = getChar(c, d, l);
  			cout << (c1 < c2 ? 2 : c1 == c2 ? 0 : 1) << "\n";
  		}
  	}
  }

  return 0;
}
