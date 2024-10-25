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
		int n;
		cin >> n;
		int e = 0, o = 0;
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (x % 2) {
				ans += e;
				o += 1;
			}
			else {
				ans += o;
				e += 1;
			}
		}
		cout << ans << "\n";
	} 

  return 0;
}
