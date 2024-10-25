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
	int ans = 0;
	for (char a = '0'; a <= '9'; ++a) {
		for (char b = '0'; b <= '9'; ++b) {
			for (char c = '0'; c <= '9'; ++c) {
				for (char d = '0'; d <= '9'; ++d) {
					string A = s;
					for (char &ca : A) {
						if (ca == a) {
							ca = b;
						}
					}
					string B = s;
					for (char &ca : B) {
						if (ca == c) {
							ca = d;
						}
					}
					if (A[0] != '0' && B[0] != '0') {
						ans = max(ans, abs(stoi(A) - stoi(B)));
					}
				}
			}
		}
	} 
	cout << ans;

  return 0;
}
