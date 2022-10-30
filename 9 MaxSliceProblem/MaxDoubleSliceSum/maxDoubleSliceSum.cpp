#include <limits>

int solution(vector<int> &A) {
  int sum = 0;
  int output = 0;
  int sum2 = 0;

  for (int i = 3; i < (int)A.size(); i++) {
    sum2 = max(sum2 + A[i - 2], 0);
    sum = max(sum2, sum + A[i - 1]);
    output = max(output, sum);
  }

  return output;
}