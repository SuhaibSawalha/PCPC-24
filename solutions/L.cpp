#include <bits/stdc++.h>
using namespace std;
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	} 
	sort(a.begin(), a.end());
	int l = 0;
	long long ans = 0;
	for (int r = 0; r < n; ++r) {
		while (a[r] - a[l] > x) {
			++l;
		}
		int d = r - l;
		ans += d * 1LL * (d - 1) / 2;
	}
	cout << ans;

  return 0;
}
