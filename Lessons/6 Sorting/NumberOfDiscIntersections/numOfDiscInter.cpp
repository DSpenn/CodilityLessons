#include <algorithm>
#include <vector>
int solution(vector<int> &A) {
  vector<long> range1(A.size());
  vector<long> range2(A.size());
  for (size_t i = 0; i < A.size(); i++) {
    range1[i] = i - A[i];
    range2[i] = i + A[i];
  }
  sort(range1.begin(), range1.end());
  sort(range2.begin(), range2.end());

  int result = 0;
  int j = 0, k = 0;
  while (j < A.size()) {
    while (k < A.size() && range2[j] >= range1[k]) 
    k++;
    result += k - j - 1;
    j++;
    if (result > 10000000) return -1;
  }
  return result;
}
