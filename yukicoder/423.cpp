#include "template.hpp"

int main() {
  string s;
  cin >> s;
  cout << s << (s == "ham" ? "" : "ham") << endl;
}
