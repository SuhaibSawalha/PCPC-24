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

  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size(), ans = 1, inv = Inv(26);
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] == '?' || s[n - i - 1] == '?') {
        ans = mul(ans, inv);
      }
      else if (s[i] != s[n - i - 1]) {
        ans = 0;
        break;
      }
    }
    cout << ans << "\n";
  } 

  return 0;
}
