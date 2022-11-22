#include <bits/stdc++.h>
#include <math.h>
#include <vector>
vector<int> solution(vector<int> &A, vector<int> &B) {
  int L = A.size();
  vector<int> result(L);
  int maxB = *std::max_element(B.begin(), B.end());
  int max = *std::max_element(A.begin(), A.end());
  vector<int> modules(L, 0);

  for (int i = 0; i < L; i++) {
    modules[i] = (1 << B[i]) - 1;
  }

  vector<int> fibs;
  fibs.push_back(0);
  fibs.push_back(1);
  for (int i = 2; i < L + 2; i++) {
    fibs.push_back(fibs[i - 1] + fibs[i - 2]);
  }

  for (auto x = 0; x < L; x += 1) {
    result[x] = (fibs[A[x] + 1] & modules[x]);
  }

  return result;
}
