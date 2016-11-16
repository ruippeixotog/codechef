#include <algorithm>
#include <cstdio>

#define MAXK 10000

using namespace std;

int units[MAXK];

int main() {
  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d", &n);

    int last = 0;
    for(int i = 0; i < n; i++) {
      int a; scanf("%d", &a);
      units[i] = a - last;
      last = a;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
      int b; scanf("%d", &b);
      if(b <= units[i]) cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
