import java.util.Arrays;
class Solution {
  public int[] solution(int N, int[] A) {
    int[] counters = new int[N];
    int max = 0;
    int lastMax = 0;

    for (int k = 0; k < A.length; k++) {
      if (A[k] <= N) {
        counters[A[k] - 1] = Math.max(counters[A[k] - 1], lastMax);
        counters[A[k] - 1]++;
        max = Math.max(max, counters[A[k] - 1]);
      } else {
        lastMax = max;
      }
    }
    for (int i = 0; i < counters.length; i++) {
      counters[i] = Math.max(counters[i], lastMax);
    }
    // Arrays.fill(counters, max);
    return counters;
  }
}