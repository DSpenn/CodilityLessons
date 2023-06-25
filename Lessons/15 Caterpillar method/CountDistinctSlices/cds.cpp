#include <algorithm>
#include <vector>

int solution(int M, vector<int> &A) {
  if (A.size() == 1) return 1;
  int LIMIT = 1000000000;
  vector<int> lastPos(M + 1, 0);
  fill(lastPos.begin(), lastPos.end(), -1);
  int count = 0;
  int start = 0;

  for (size_t i = 0; i < A.size(); i += 1) {
    if (lastPos[A[i]] + 1 > start) {
      start = lastPos[A[i]] + 1;
    }
    lastPos[A[i]] = i;
    count += i - start + 1;

    if (count > LIMIT) break;
  }
  return count > LIMIT ? LIMIT : count;
}
