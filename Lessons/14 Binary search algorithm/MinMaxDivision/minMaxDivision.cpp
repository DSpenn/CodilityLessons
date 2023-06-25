#include <math.h>
#include <algorithm>
#include <numeric>
#include <vector>
int solution(int K, int M, vector<int> &A) {
  int begin = *std::max_element(A.begin(), A.end());
  int end = std::accumulate(A.begin(), A.end(), 0);  // sum
  int result = 0;
  while (begin <= end) {
    int mid = floor((begin + end) / 2);

    int currentSum = 0;
    int blocks = 1;

    for (int i = 0; i < A.size(); i++) {
      if (currentSum + A[i] > mid) {
        blocks++;
        currentSum = A[i];
        if (blocks > K) {
          break;
        }
      } else {
        currentSum += A[i];
      }
    }
    if (blocks > K) {
      begin = mid + 1;
    } else {
      result = mid;
      end = mid - 1;
    }
  }
  return result;
}
