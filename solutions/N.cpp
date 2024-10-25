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

int fastpow (int v, long long p) {
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

int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int k;
  cin >> s >> k;
  int n = s.size(), ans = 0;
  int mult = mul(sub(fastpow(2, n * 1LL * k), 1), Inv(sub(fastpow(2, n), 1)));
  for (int i = 0; i + 1 < n; ++i) {
    if (((s[i] - '0') * 10 + s[i + 1] - '0') % 4 == 0) {
      ans = add(ans, mul(fastpow(2, i), mult));
    }
  }
  if (((s[n - 1] - '0') * 10 + s[0] - '0') % 4 == 0) {
    mult = mul(sub(fastpow(2, n * 1LL * (k - 1)), 1), Inv(sub(fastpow(2, n), 1)));
    ans = add(ans, mul(fastpow(2, n - 1), mult));
  }
  cout << ans;

  return 0;
}
