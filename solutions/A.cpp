#include <bits/stdc++.h>
using namespace std;
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, n;
    cin >> x >> y >> n;
    cout << min(x * n, (n / 3) * y + (n % 3) * x) << "\n";
  } 

  return 0;
}
