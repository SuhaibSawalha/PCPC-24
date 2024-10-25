#include <bits/stdc++.h>
using namespace std;
    
const int N = 1e6 + 5;
bool is_prime[N];
int dif_primes[N];
long long ans[N];

void sieve () {
  for (int i = 2; i < N; ++i) {
    is_prime[i] = 1;
  }
  for (int i = 2; i < N; ++i) {
    if (is_prime[i]) {
      dif_primes[i] = 1;
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = 0;
        ++dif_primes[j];
      }
    }
  }
}

int main () {

  #ifndef ONLINE_JUDGE
    freopen("Satoru","r",stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int pw2[20];
  pw2[0] = 1;
  for (int i = 1; i < 20; ++i) {
    pw2[i] = pw2[i - 1] * 2;
  }
  sieve();
  for (int g = 1; g < N; ++g) {
    for (int l = g; l + g < N; l += g) {
      int left = l / g;
      if (dif_primes[left] <= 1) {
        ans[l + g]++;
      }
      else {
        ans[l + g] += pw2[dif_primes[left] - 1];
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    cout << ans[x] << "\n";
  }

  return 0;
}
