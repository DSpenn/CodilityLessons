import java.util.*;

class Solution {
  public int[] solution(int[] A) {
    int[] counters = new int[A.length * 2 + 1];
    for (int x = 0; x < A.length; x += 1) {
      counters[A[x]] += 1;
    }
    // System.out.println(Arrays.toString(counters));
    int[] a = new int[A.length];
    for (int x = 0; x < A.length; x++) {
      int nonDivisor = A.length;
      for (int i = 1; i * i <= A[x]; i += 1) {
        if (A[x] % i != 0) continue;
        nonDivisor -= counters[i];
        if (i * i != A[x]) {
          nonDivisor -= counters[A[x] / i];
        }
        a[x] = nonDivisor;
      }
    }
    // System.out.println(Arrays.toString(a));
    return a;
  }
}