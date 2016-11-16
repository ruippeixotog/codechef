#include <cmath>
#include <cstdio>
#include <iterator>
#include <map>
#include <vector>

#define MAXK 100000

#define PREFIX_SIZE 40
#define SUFFIX_SIZE 60

using namespace std;

map<int, vector<int>> prefixes;
map<int, int> lisSizes;

void pushPrefixMult(vector<int>& prefix, int times, int mult) {
  while(times--) {
    int base = SUFFIX_SIZE + (int) prefix.size() + 1;
    for (int k = 0; k < mult; k++)
      prefix.push_back(base + mult - k - 1);
  }
}

void popPrefixMult(vector<int>& prefix, int times, int mult) {
  for(int i = 0; i < times * mult; i++) prefix.pop_back();
}

void buildPrefixMap(vector<int> &prefix, int mult, int lisSize, int lisCnt,
                    int leftNumbers) {
  if(lisCnt > MAXK) return;

  if(mult == PREFIX_SIZE) {
    lisSize += leftNumbers;

    if(!lisSizes.count(lisCnt) || lisSize < lisSizes[lisCnt]) {
      pushPrefixMult(prefix, leftNumbers, 1);
      lisSizes[lisCnt] = lisSize;
      prefixes[lisCnt] = prefix;
      popPrefixMult(prefix, leftNumbers, 1);
    }
    return;
  }

  for(int i = 0; i <= leftNumbers / mult; i++) {
    pushPrefixMult(prefix, i, mult);
    buildPrefixMap(prefix, mult + 1, lisSize + i, lisCnt * pow(mult, i),
                   leftNumbers - i * mult);
    popPrefixMult(prefix, i, mult);
  }
}

void buildSuffix(vector<int>& prefix, int lisSize, int remaining) {
  int ni = 1;
  for(int i = 0; i < lisSize - 2; i++)
    prefix.push_back(ni++);

  int a = SUFFIX_SIZE, aMin = (SUFFIX_SIZE + ni) / 2, b = aMin;

  for(int i = lisSize - 2; i < SUFFIX_SIZE; i++) {
    if(remaining >= a - aMin) {
      prefix.push_back(b--);
      remaining -= a - aMin;
    } else {
      prefix.push_back(a--);
    }
  }
}

int main() {
  vector<int> tmp;
  buildPrefixMap(tmp, 2, 0, 1, PREFIX_SIZE);

  int t; scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    int k; scanf("%d", &k);

    if(k == 1) {
       printf("1\n1\n");
    } else {
      auto prefixInfo = prev(prefixes.upper_bound(k));
      vector<int> sol = prefixInfo->second;
      buildSuffix(sol, lisSizes[prefixInfo->first], k - prefixInfo->first);

      printf("%d\n", (int) sol.size());
      for(int i = 0; i < (int) sol.size(); i++)
        printf(i == (int) sol.size() - 1 ? "%d\n" : "%d ", sol[i]);
    }
  }
  return 0;
}
