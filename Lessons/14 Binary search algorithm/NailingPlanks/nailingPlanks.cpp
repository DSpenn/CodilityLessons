#include <math.h>
#include <vector>

int nailed(vector<int> &a, vector<int> &b, vector<int> &c, int n) {
  vector<int> pNails(2 * c.size() + 1);
  fill(pNails.begin(), pNails.end(), 0);
  for (int x = 0; x < n; x += 1) {
    pNails[c[x]] += 1;
  }
  for (int x = 1; x < pNails.size(); x += 1) {
    pNails[x] += pNails[x - 1];
  }
  for (int x = 0; x < a.size(); x += 1) {
    if (pNails[b[x]] <= pNails[a[x] - 1]) return false;
  }
  return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
  if (C.size() == 1) {
    return A[0] <= C[0] && C[0] <= B[0] ? 1 : -1;
  }

  int begin = 0;
  int end = C.size() - 1;
  int output = -1;

  while (begin <= end) {
    int mid = (int)floor((begin + end) / 2);
    if (nailed(A, B, C, (mid + 1))) {
      end = mid - 1;
      output = mid + 1;
    } else {
      begin = mid + 1;
    }
  }
  return output;
}