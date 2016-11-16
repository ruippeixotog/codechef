#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define INF 1e9

using namespace std;

int hist[26];

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    string word; int k; cin >> word >> k;

    memset(hist, 0, sizeof(hist));
    for(char c : word) hist[c - 'a']++;

    int best = INF;
    for(int i = 0; i < (int) word.length(); i++) {
      int toRemove = 0;
      for(int j = 0; j < 26; j++) {
        if(hist[j] < i) toRemove += hist[j];
        else toRemove += max(0, hist[j] - i - k);
      }
      best = min(best, toRemove);
    }

    printf("%d\n", best);
  }
  return 0;
}
