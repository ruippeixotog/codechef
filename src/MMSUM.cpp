#include <algorithm>
#include <cstdio>

#define MAXK 100000
#define INF 1e18

using namespace std;

typedef long long ll;

int a[MAXK];

ll dp[MAXK + 1][2];

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    dp[0][0] = dp[0][1] = 0;

    ll best = -INF;
    for(int i = 1; i <= n; i++) {
      dp[i][0] = max(0LL, dp[i - 1][0]) + a[i - 1];
      dp[i][1] = max(0LL, dp[i - 1][1]) + a[i - 1];
      if (i > 1) dp[i][1] = max(dp[i][1], dp[i - 1][0]);

      best = max(best, max(dp[i][0], dp[i][1]));
    }

    printf("%lld\n", best);
  }
  return 0;
}
