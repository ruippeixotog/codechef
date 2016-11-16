#include <cstdio>

#define MAXN 100000
#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

ll minv(ll a) { return mpow(a, MOD - 2); }
ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }

ll a[MAXN];

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, x; ll m; scanf("%d %d %lld", &n, &x, &m);
    for(int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    ll res = a[x - 1] % MOD;
    ll comb = 1, cn = m - 1, ck = 0;
    for(int i = x - 2; i >= 0; i--) {
      comb = mdiv(mmul(comb, (++cn) % MOD), ++ck);
      res = madd(res, mmul(a[i] % MOD, comb));
    }
    printf("%lld\n", res);
  }
  return 0;
}
