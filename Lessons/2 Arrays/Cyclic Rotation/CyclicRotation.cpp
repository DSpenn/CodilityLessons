#include <algorithm>

vector<int> solution(vector<int> &A, int K) {
  if (A.size() < 2) return A;
  if (K == 0) return A;
  K = K % A.size();
  rotate(A.rbegin(), A.rbegin() + K, A.rend());
  return A;
}
