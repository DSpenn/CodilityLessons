#include <algorithm>
#include <cmath>

int solution(vector<int> &A) {
  sort(A.begin(), A.end());
  int start = 0;
  int end = A.size() - 1;
  int currentSum = 0;
  int minAbsSum = abs(A[start] + A[end]);
  while (start <= end) {
    currentSum = A[start] + A[end];
    if (currentSum == 0) return 0;
    minAbsSum = min(minAbsSum, abs(currentSum));
    if (currentSum <= 0) {
      start += 1;
    } else {
      end -= 1;
    }
  }
  return minAbsSum;
}
