#include <iostream>
#include <string>

#define ull unsigned long long

#define MAXL 1000000000

using namespace std;

ull ullpow(ull x, ull p) {
  if (p == 0) return 1;
  ull tmp = ullpow(x, p / 2);
  if(tmp > MAXL) return MAXL; // avoid overflow
  if (p % 2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int main() {
  int t; cin >> t;
  while(t--) {
    ull l, d, s, c; cin >> l >> d >> s >> c;
    ull likes = s * ullpow(1 + c, d - 1);
    cout << (likes >= l ? "ALIVE AND KICKING" : "DEAD AND ROTTING") << endl;
  }
}
