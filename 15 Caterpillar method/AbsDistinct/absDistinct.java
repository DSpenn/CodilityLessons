import java.util.*;

class Solution {
  public int solution(int[] A) {
    Set<Integer> s = new HashSet<Integer>();
    for (int i = 0; i < A.length; i++) {
      s.add(Math.abs(A[i]));
    }
    return s.size();
  }
}
