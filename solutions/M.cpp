#include <bits/stdc++.h>
using namespace std;
    
const int mod = 1e9 + 7;
int add (int a, int b) {
	return (a + b) % mod;
}
int mul (int a, int b) {
	return (a * 1LL * b) % mod;
}
int sub (int a, int b) {
	return ((a - b) % mod + mod) % mod;
}

int dp[100][10][2], vis[100][10][2], vid;
string s, k;

int calc (int i, int p, int eq) {
	if (i == k.size()) {
		return 1;
	}
	int &ret = dp[i][p][eq];
	if (vis[i][p][eq] == vid) {
		return ret;
	}
	vis[i][p][eq] = vid;
	ret = 0;
	for (int x = 0; x <= (eq ? k[i] : '9') - '0'; ++x) {
		if (s[i - 1] == '>' && p <= x) {
			continue;
		}
		if (s[i - 1] == '<' && p >= x) {
			continue;
		} 
		ret = add(ret, calc(i + 1, x, eq & (x == k[i] - '0')));
	}
	return ret;
}

int solve (string k, string s) {
	::k = k;
	::s = s;
	++vid;
	int ans = 0;
	for (int i = 1; i <= k[0] - '0'; ++i) {
		ans = add(ans, calc(1, i, i == k[0] - '0'));
	}
	return ans;
}

bool ok (string k, string s) {
	for (int i = 0; i + 1 < k.size(); ++i) {
		if (s[i] == '<' && k[i] >= k[i + 1]) {
			return 0;
		}
		if (s[i] == '>' && k[i] <= k[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tt;
  cin >> tt;
  while (tt--) {
  	string l, r, s;
  	cin >> l >> r >> s;
  	cout << add(sub(solve(r, s), solve(l, s)), ok(l, s)) << "\n";
  }

  return 0;
}
