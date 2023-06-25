import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    Arrays.sort(A);
    int start = 0;
    int end = A.length - 1;
    int currentSum = 0;
    int minAbsSum = Math.abs(A[start] + A[end]);
    while (start <= end) {
      currentSum = A[start] + A[end];
      if (currentSum == 0) return 0;
      minAbsSum = Math.min(minAbsSum, Math.abs(currentSum));
      if (currentSum <= 0) {
        start += 1;
      } else {
        end -= 1;
      }
    }
    return minAbsSum;
  }
}
