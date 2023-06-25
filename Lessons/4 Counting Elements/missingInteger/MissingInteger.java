import java.io.*;
import java.util.*;

class Solution {
  public int solution(int[] A) {
    if (A.length == 0) {
      return 1;
    }
    Set<Integer> set = new HashSet<Integer>();
    for (int i = 0; i < A.length; i++) {
      set.add(A[i]);
    }
    int i = 1;
    while (set.contains(i)) i++;

    return i;
  }
}
