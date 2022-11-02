import java.util.Arrays;

class Solution {
  public int solution(int M, int[] A) {
    if (A.length == 1)
      return 1;

    // Arrays.sort(A);
    int[] B = new int[M + 1];
    Arrays.fill(B, -1);

    int count = 0;
    int start = 0;
    int LIMIT = 1000000000;
    // System.out.println(Arrays.toString(B));
    for (int i = 0; i < A.length; i++) {
      if (B[A[i]] + 1 > start) {
        start = B[A[i]] + 1;
      }
      B[A[i]] = i;
      count += i - start + 1;

      if (count > LIMIT)
        break;
    }
    return count > LIMIT ? LIMIT : count;
  }
}