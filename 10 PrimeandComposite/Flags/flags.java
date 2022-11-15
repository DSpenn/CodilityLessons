//import java.util.*;
import java.util.ArrayList;

class Solution {
  public int solution(int[] A) {
    if (A.length <= 2) return 0;
    ArrayList<Integer> peaks = new ArrayList<Integer>();
    for (int i = 1; i < A.length - 1; i += 1) {
      if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
        peaks.add(i);
      }
    }
    if (peaks.size() <= 2) return peaks.size();
    int maxFlag = (int)Math.floor(
        Math.sqrt(peaks.get(peaks.size() - 1) - peaks.get(0)) + 1);
    int count = 1;
    int curPos = 0;
    for (int i = maxFlag; i >= 2; i -= 1) {
      count = 1;
      curPos = peaks.get(0);
      for (int x = 1; x < peaks.size(); x += 1) {
        if (curPos + i <= peaks.get(x)) {
          curPos = peaks.get(x);
          count += 1;
        }
      }
      if (count >= i) return i;
    }
    return 1;
  }
}