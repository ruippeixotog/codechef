#include <cstdio>
#include <vector>

#define MAXN 50

using namespace std;

vector<int> adjs[MAXN];

void add(int u, int v) {
  adjs[u].push_back(v);
}

int main() {
  add(0, 1); add(0, 2);
  add(3, 1); add(3, 2);
  add(4, 1); add(5, 2); add(6, 3);

  for(int i = 7; i < MAXN; i++) {
    add(i, 1); add(i, 2);
  }

  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    if(n < 7) printf("-1\n");
    else {
      printf("%d\n", 7 + (n - 7) * 2);
      for(int i = 0; i < n; i++) {
        for(int adj: adjs[i])
          printf("%d %d\n", i + 1, adj + 1);
      }
      printf("1\n");
    }
  }
  return 0;
}
