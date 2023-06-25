import java.util.*;
class Solution {
  public int solution(int[] A) {
    if (A.length == 0) {
      return -1;
    }
    HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
    for (int i : A) {
      if (freq.containsKey(i))
        freq.put(i, freq.get(i) + 1);
      else
        freq.put(i, 1);
    }

    int half = A.length / 2;
    int domin = Collections.max(freq.values());

    if (domin <= half)
      return -1;

    int toFind = 0;

    for (Map.Entry e : freq.entrySet()) {
      if (domin == (int) e.getValue()) {
        toFind = (int) e.getKey();
      }
    }

    for (int i = 0; i < A.length; i++) {
      if (A[i] == toFind) {
        return i;
      }
    }

    return -1;
  }
}