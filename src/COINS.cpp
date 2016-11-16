#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

map<int, ll> mem;

ll find(int k) {
  if(k == 0) return 0;
  if(!mem.count(k)) {
    mem[k] = max((ll) k, find(k / 2) + find(k / 3) + find(k / 4));
  }
  return mem[k];
}

int main() {
  int n;
  while(scanf("%d", &n) > 0) {
    printf("%lld\n", find(n));
  }
  return 0;
}
