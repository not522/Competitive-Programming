#include "template.hpp"

int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (uint i = 0; i < s.size();) {
    if (s.substr(i, 7) == "remaerd") {
      i += 7;
    } else if (s.substr(i, 5) == "maerd") {
      i += 5;
    } else if (s.substr(i, 6) == "resare") {
      i += 6;
    } else if (s.substr(i, 5) == "esare") {
      i += 5;
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
