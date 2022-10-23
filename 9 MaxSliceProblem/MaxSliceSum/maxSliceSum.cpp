#include <limits.h>

int solution(vector<int> &A) {
  int sum = 0;
  int max = A[0];
  int maxCell = A[0];
  for (int a : A) {
    sum = std::max(0, sum + a);
    max = std::max(max, sum);
    maxCell = std::max(maxCell, a);
  }
  if (max == 0) return maxCell;
  return max;
}