#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXA 1000000

using namespace std;

vector<vector<int>> a;

vector<pair<int, int>> lines[MAXA + 1], cols[MAXA + 1];

int countForK(int k) {
  if(lines[k].empty()) return 0;

  vector<int> bestLines, bestCols;
  int bestLineCnt = 0, bestColCnt = 0;

  for(auto line : lines[k]) {
    if(line.second >= bestLineCnt) {
      if(line.second > bestLineCnt) bestLines.clear();
      bestLines.push_back(line.first);
      bestLineCnt = line.second;
    }
  }

  for(auto col : cols[k]) {
    if(col.second >= bestColCnt) {
      if(col.second > bestColCnt) bestCols.clear();
      bestCols.push_back(col.first);
      bestColCnt = col.second;
    }
  }

  for(int i : bestLines) {
    for(int j : bestCols) {
      if(a[i][j] != k) return bestLineCnt + bestColCnt;
    }
  }
  return bestLineCnt + bestColCnt - 1;
}

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m; scanf("%d %d", &n, &m);

    a.resize(n);
    for(int i = 0; i < n; i++) {
      a[i].resize(m);
      for(int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    for(int k = 1; k <= MAXA; k++) {
      lines[k].clear(); cols[k].clear();
    }

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if (!lines[a[i][j]].empty() && lines[a[i][j]].back().first == i) {
          lines[a[i][j]].back().second++;
        } else {
          lines[a[i][j]].push_back({i, 1});
        }
      }
    }

    for(int j = 0; j < m; j++) {
      for(int i = 0; i < n; i++) {
        if (!cols[a[i][j]].empty() && cols[a[i][j]].back().first == j) {
          cols[a[i][j]].back().second++;
        } else {
          cols[a[i][j]].push_back({j, 1});
        }
      }
    }

    int best = 0;
    for(int k = 1; k <= MAXA; k++) {
      best = max(best, countForK(k));
    }
    printf("%d\n", best);
  }
  return 0;
}
