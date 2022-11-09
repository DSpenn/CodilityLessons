int solution(int K, vector<int> &A) {
  if (K == 1) return A.size();

  int count = 0;
  int sum = 0;

  for (auto i = 0; i < A.size(); i += 1) {
    sum += A[i];
    if (sum >= K) {
      sum = 0;
      count += 1;
    }
  }
  return count;
}