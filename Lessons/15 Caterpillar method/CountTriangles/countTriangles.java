import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    Arrays.sort(A);
    int count = 0;
    int k = 0;
    for (int i = 0; i < A.length - 2; i += 1) {
      k = i + 2;
      for (int j = i + 1; j < A.length; j++) {
        while (k < A.length && A[i] + A[j] > A[k]) {
          k += 1;
          count += k - j - 1;
        }
      }
    }
    return count;
  }
}
