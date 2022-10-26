#include <set>
#include <string>
#include <vector>
int solution(int N) {
  int bin;
  vector<int> b;
  set<int> counts;
  int zero = 0;
  bool gap = false;

  while (N > 0) {
    bin = N % 2;
    b.push_back(bin);
    N /= 2;
  }

  // for (int x : b) { cout << x; } print binary representation of number vector

  for (unsigned int y = 0; y < b.size(); y += 1) {
    if (b.at(y) == 0 && gap == true) {
      zero++;
    }
    if (b.at(y) == 1) {
      gap = true;
      counts.insert(zero);
      zero = 0;
    }
  }
  // for (int i : counts) { cout << i << ' '; }  print gap counts set
  return (counts.size() == 0) ? 0 : *counts.rbegin(); 
}
