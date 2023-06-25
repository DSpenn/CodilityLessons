#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
  std::sort(A.begin(), A.end());
  int count = 0;
  int k = 0;
  for (int i = 0; i < A.size() - 2; i += 1) {
    k = i + 2;
    for (int j = i + 1; j < A.size(); j++) {
      while (k < A.size() && A[i] + A[j] > A[k]) {
        k += 1;
        count += k - j - 1;
      }
    }
  }
  return count;
}
