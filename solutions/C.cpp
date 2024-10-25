#include <bits/stdc++.h>
using namespace std;
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string s;
  cin >> n >> s;
  long long p = 1, ans = 0;
  for (int i = n - 1; ~i; --i) {
    if (s[i] == '1') {
      ans += p;
    }
    p *= 2;
  }
  cout << ans;

  return 0;
}
