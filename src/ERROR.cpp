#include <iostream>
#include <string>

using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    string str; cin >> str;
    bool good = false;
    for(int i = 0; i < (int) str.length() - 2; i++) {
      if(str[i] == str[i + 2] && str[i] != str[i + 1]) {
        good = true;
        break;
      }
    }
    cout << (good ? "Good" : "Bad") << endl;
  }
}
