#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b, ll mod) { return (a * b) % mod; }

ll mpow(ll a, ll p, ll mod) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2, mod);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow, mod) : halfPow, mod);
}

ll randBetween(ll a, ll b) {
  ll r = ((ll)(rand() & ~(1 << 31)) << 32) | rand();
  return a + r % (b - a + 1);
}

bool isPrime(ll n, int bases = 10) {
  if (n == 2 || n == 3) return true;
  if (n <= 1 || n % 2 == 0) return false;

  // Write (n - 1) as (d * 2^s) by factoring powers of 2 from (n - 1)
  int s = 0;
  for (ll m = n - 1; m % 2 == 0; ++s, m /= 2);
  ll d = (n - 1) / (1 << s);

  for(int i = 0; i < bases; i++) {
    ll a = randBetween(2, n - 2);
    ll x = mpow(a, d, n);

    if (x == 1 || x == n - 1)
      continue;

    bool found = false;
    for(int r = 1; r <= s - 1; r++) {
      x = mpow(x, 2, n);
      if(x == 1) return false;
      if(x == n - 1) { found = true; break; }
    }
    if(!found) return false;
  }
  return true;
}

int main() {
  srand(time(NULL));

  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int m, n; scanf("%d %d", &m, &n);

    if(tc > 1) printf("\n");
    for(int i = m; i <= n; i++) {
      if(isPrime(i, 20)) printf("%d\n", i);
    }
  }
  return 0;
}
