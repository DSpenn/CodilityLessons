#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
  vector<int> a(A.size());
  a[0] = A[0];
  for (auto x = 1; x < A.size(); x += 1) {
    int max = a[x - 1] + A[x];
    for (auto y = 1; y <= 6; y += 1) {
      if (x - y >= 0) {
        max = std::max(a[x - y] + A[x], max);
      }
    }
    a[x] = max;
  }
  return a[A.size() - 1];
}
