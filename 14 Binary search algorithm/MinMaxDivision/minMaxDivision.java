import java.util.Arrays;

class Solution {
  public int solution(int K, int M, int[] A) {
    int begin = Arrays.stream(A).max().getAsInt();
    int end = Arrays.stream(A).reduce(0, Integer::sum);
    int result = 0;

    while (begin <= end) {
      int mid = (int) Math.floor((begin + end) / 2);
      int currentSum = 0;
      int blocks = 1;

      for (int i = 0; i < A.length; i++) {
        if (currentSum + A[i] > mid) {
          blocks++;
          currentSum = A[i];
          if (blocks > K) {
            break;
          }
        } else {
          currentSum += A[i];
        }
      }
      if (blocks > K) {
        begin = mid + 1;
      } else {
        result = mid;
        end = mid - 1;
      }
    }
    return result;
  }
}
