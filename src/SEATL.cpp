#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 1000000
#define MAXM 1000

using namespace std;

typedef long long ll;
typedef long double ld;

vector<vector<int>> a;

map<int, int> rowFreq[MAXN], colFreq[MAXM];
int colMax[MAXM];

#define N 1000
#define M 1000

void gen() {
  cout << 1 << endl;
  cout << N << " " << M << endl;

  int x[N][M];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      x[i][j] = (i * N) + j;
    }
    random_shuffle(x[i], x[i] + M);
  }

  for(int i = 0; i < N; i++) {
    cout << x[i][0];
    for(int j = 1; j < M; j++) cout << " " << x[i][j];
    cout << endl;
  }
}

int main() {
//  gen();
//  return 0;

  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m; scanf("%d %d", &n, &m);
    int ni = max(n, m), mi = min(n, m);

    a.resize(ni);
    for(int i = 0; i < ni; i++) {
      a[i].resize(mi);
      for(int j = 0; j < mi; j++)
        scanf("%d", &a[i][j]);
    }

    for(int i = 0; i < ni; i++) rowFreq[i].clear();
    for(int j = 0; j < mi; j++) colFreq[j].clear();

    for(int i = 0; i < ni; i++) {
      for(int j = 0; j < mi; j++) {
        rowFreq[i][a[i][j]]++; colFreq[j][a[i][j]]++;
      }
    }

    memset(colMax, 0, sizeof(colMax));
    for(int i = 0; i < mi; i++) {
      for(auto e: colFreq[i])
        colMax[i] = max(colMax[i], e.second);
    }

    int best = 0;
    for(int i = 0; i < ni; i++) {
      cerr << i << endl;
      for(int j = 0; j < mi; j++) {
        int best2 = colMax[j];
        for(auto e: rowFreq[i]) {
          best2 = max(best2, e.second + colFreq[j][e.first] -
              (e.first == a[i][j]));
        }
        best = max(best, best2);
      }
    }
    printf("%d\n", best);
  }
  return 0;
}
