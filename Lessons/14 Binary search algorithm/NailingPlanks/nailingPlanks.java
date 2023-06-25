import java.util.*;

class Solution {
  public int solution(int[] A, int[] B, int[] C) {
    if (C.length == 1) {
      return A[0] <= C[0] && C[0] <= B[0] ? 1 : -1;
    }
    int begin = 0;
    int end = C.length - 1;
    int output = -1;

    while (begin <= end) {
      int mid = (int) Math.floor((begin + end) / 2);
      if (nailed(A, B, C, (mid + 1))) {
        end = mid - 1;
        output = mid + 1;
      } else {
        begin = mid + 1;
      }
    }
    return output;
  }

  boolean nailed(int[] a, int[] b, int[] c, int n) {
    int[] pNails = new int[(2 * c.length + 1)];
    Arrays.fill(pNails, 0);
    for (int x = 0; x < n; x += 1) {
      pNails[c[x]] += 1;
    }
    for (int x = 1; x < pNails.length; x += 1) {
      pNails[x] += pNails[x - 1];
    }
    for (int x = 0; x < a.length; x += 1) {
      if (pNails[b[x]] <= pNails[a[x] - 1])
        return false;
    }
    return true;
  }
}