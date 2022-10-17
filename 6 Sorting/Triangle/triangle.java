import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    if (A.length < 3) { return 0; }

    Arrays.sort(A);
    for (int x = 2; x < A.length; x++) {
      if ((long)A[x-2] + (long)A[x-1] > (long)A[x]) { return 1; }
    }
    return 0;
  }
}
