#include <bits/stdc++.h>
using namespace std;
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  map<int, array<int, 2>> ans;
  int last_one = -1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      last_one = i;
    }
    long long val = 0;
    for (int j = 0; j < 32 && i + j < s.size(); ++j) {
      val = val * 2 + s[i + j] -'0';
      if (ans.find(val) == ans.end()) {
        ans[val] = {last_one + (i != last_one), i + j};
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    auto it = ans.lower_bound(l);
    if (it == ans.end() || it->first > r) {
      cout << "-1 -1\n";
    }
    else {
      cout << it->second[0] + 1 << " " << it->second[1] + 1 << "\n";
    }
  }

  return 0;
}
