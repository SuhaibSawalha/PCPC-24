#include <bits/stdc++.h>
using namespace std;
    
int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n;
	cin >> n;
	int firstp = n, firstn = n;
	int lastp = -1, lastn = -1;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == 1) {
			firstp = min(firstp, i);
			lastp = max(lastp, i);
		}
		else if (a == -1) {
			firstn = min(firstn, i);
			lastn = max(lastn, i);
		}
	} 
	if (firstp == n) {
		cout << lastn - firstn + 1;
		return 0;
	}
	if (firstn == n) {
		cout << lastp - firstp + 1;
		return 0;
	}
	int ans = n;
	while (firstn != -1 && lastp != n) {
		ans = min(ans, max(lastp, lastn) - min(firstp, firstn) + 1);
		lastp += 1;
		firstp += 1;
		lastn -= 1;
		firstn -= 1;
	}
	cout << ans;

  return 0;
}
