#include <algorithm>
#include <vector>

vector<int> solution(int N, vector<int> &A) {
  vector<int> counters(N, 0);
  int min = 0;
  int max = 0;
  for (int k = 0; k < A.size(); k++) {
    if (A[k] <= N) {
      counters[A[k] - 1] = std::max(counters[A[k] - 1], min);
      counters[A[k] - 1]++;
      max = std::max(max, counters[A[k] - 1]);
    } else {
      min = max;
    }
  }
  for (int i = 0; i < counters.size(); i++) {
    counters[i] = std::max(counters[i], min);
  }
  return counters;
}
