import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
  public int solution(int[] A) {
    if (A.length == 0) {
      return 0;
    }

    Set<Integer> Set = new HashSet<>();
    for (int element : A) {
      Set.add(element);
    }
    // System.out.println(Set.size());
    return Set.size();
  }
}
