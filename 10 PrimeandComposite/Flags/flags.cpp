#include <math.h>
#include <vector>

int solution(vector<int> &A) {
  if (A.size() <= 2) return 0;
  vector<int> peaks;
  for (int i = 1; i < A.size() - 1; i += 1) {
    if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
      peaks.push_back(i);
    }
  }

  if (peaks.size() <= 2) return peaks.size();

  int maxFlag = std::round(sqrt(peaks[peaks.size() - 1] - peaks[0]) + 1);

  int count = 1;
  int curPos = peaks[0];
  for (int i = maxFlag; i >= 2; i -= 1) {
    count = 1;
    curPos = peaks[0];
    for (int x = 1; x < peaks.size(); x += 1) {
      if (curPos + i <= peaks[x]) {
        curPos = peaks[x];
        count += 1;
      }
    }
    if (count >= i) return i;
  }
}
