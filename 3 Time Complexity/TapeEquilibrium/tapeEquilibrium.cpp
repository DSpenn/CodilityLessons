#include <limits.h>
#include <cmath>

int solution(vector<int> &A) {
  int totalSum = 0;
  int min = INT_MAX;

  for (int i : A) totalSum += i;
  for (unsigned int i = 0; i < A.size() - 1; i++) {
    totalSum -= 2 * A[i];
    if (min > std::abs(totalSum)) {
      min = std::abs(totalSum);
    }
  }
  return min;
}