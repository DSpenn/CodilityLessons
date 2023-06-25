#include <algorithm>

int solution(vector<int> &A) {
  if (A.size() < 3) {
    return 0;
  }
  sort(A.begin(), A.end());

  for (unsigned int x = 2; x < A.size(); x++) {
    if ((long long)A[x - 2] + A[x - 1] > A[x]) return true;
  }
  return 0;
}
