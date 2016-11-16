#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 100000

using namespace std;

vector<int> adjs[MAXN + 1];
vector<int> res;

void dfs(int k) {
  if(adjs[k].empty()) res.push_back(k);
  for(int adj : adjs[k]) dfs(adj);
}

int main() {
  int n; scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int r; scanf("%d", &r); adjs[r].push_back(i);
  }

  dfs(0);
  sort(res.begin(), res.end());

  printf("%d", res[0]);
  for(int i = 1; i < res.size(); i++) printf(" %d", res[i]);
  printf("\n");
  return 0;
}
