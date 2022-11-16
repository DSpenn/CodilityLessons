#include <vector>
int solution(vector<int> &A) {
  if (A.size() < 3) return 0;
  
  vector<int> peaks;

  for (int i = 1; i < A.size() - 1; i += 1) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) peaks.push_back(i);
  }
  if (peaks.size() == 0) return 0;

  //for (int x : peaks) { cout << x << " "; }  //[ 3, 5, 10 ]

  for (int i = peaks.size(); i >= 2; i -= 1) {
    if (A.size() % i == 0) {
      int K = A.size() / i;
      int x = 0;
      for (int y = 0; y < peaks.size(); y++) {
        int start = x * K;
        int end = (x + 1) * K;
        if (peaks[y] >= start && peaks[y] < end) {
          x += 1;
        }
      }
      if (x == i) return i;
    }
  }
}
