#include "minmax.hpp"
#include "string/to_integer.hpp"

int main() {
  int n;
  cin >> n;
  int64_t res = numeric_limits<int64_t>::max();
  for (int i = 0; i < n; ++i) {
    string v;
    cin >> v;
    int mx = 0;
    for (char c : v) {
      if (isdigit(c)) mx = max(mx, c - '0' + 1);
      else if (isalpha(c)) mx = max(mx, c - 'A' + 11);
    }
    chmin(res, toInteger<int64_t>(v, mx));
  }
  cout << res << endl;
}