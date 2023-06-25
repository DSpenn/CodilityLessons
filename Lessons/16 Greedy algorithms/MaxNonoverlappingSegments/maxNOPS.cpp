int solution(vector<int> &A, vector<int> &B) {
  if (A.size() == 0) return A.size();
  int count = 1;
  int ending = B[0];
  for (auto x = 1; x < B.size(); x += 1) {
    if (A[x] > ending) {
      ending = B[x];
      count += 1;
    }
  }
  return count;
}