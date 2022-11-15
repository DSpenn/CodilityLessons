import java.util.ArrayList;

class Solution {
  public int solution(int[] A) {
    if (A.length < 3) return 0;
    ArrayList<Integer> peaks = new ArrayList<Integer>();
    for (int i = 1; i < A.length - 1; i += 1) {
      if (A[i] > A[i - 1] && A[i] > A[i + 1])
        peaks.add(i);
    }
    if (peaks.size() == 0) return 0;

    for (int i = peaks.size(); i >= 2; i -= 1) {
      if (A.length % i == 0) {
        int K = A.length / i;
        int x = 0;
        for (int y = 0; y < peaks.size(); y++) {
          int start = x * K;
          int end = (x + 1) * K;
          if (peaks.get(y) >= start && peaks.get(y) < end) {
            x += 1;
          }
        }
        if (x == i)
          return i;
      }
    }
    return 1;
  }
}
