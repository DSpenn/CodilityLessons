#include <set>
#include <vector>
int solution(int N) {
  vector<int> b;
  set<int> allCounts;
  int count = 0;
  bool gap = false;

  while (N > 0) {
    b.push_back(N % 2);
    N /= 2;
  }

  for (unsigned int y = 0; y < b.size(); y++) {
    if (b[y] == 0 && gap == true) {
      count++;
    }
    if (b[y] == 1) {
      gap = true;
      allCounts.insert(count);
      count = 0;
    }
  }
  /*     for (auto it = allCounts.begin(); it!=allCounts.end();it++)
      { cout<<endl<<*it; } */

  return (allCounts.size() == 0) ? 0 : *allCounts.rbegin();
}
