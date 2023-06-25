import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    int[] a = new int[A.length];
    a[0] = A[0];
    for (int x = 1; x < A.length; x += 1) {
      int max = a[x - 1] + A[x];
      for (int y = 1; y <= 6; y += 1) {
        if (x - y >= 0) {
          max = Math.max(a[x - y] + A[x], max);
        }
      }
      a[x] = max;
    }
    return a[A.length - 1];
  }
}
