#include "count.hpp"
#include "vector.hpp"
#include "math/basic.hpp"

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  auto c = count(a);
  cout << n - 2 * ceil(n - int(c.size()), 2) << endl;
}
