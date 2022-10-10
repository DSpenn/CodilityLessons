import java.util.*;

class Solution {
    public int solution(int[] A) {
        int unpaired = 0;
        for (int number : A) {
            unpaired ^= number;
            System.out.println(unpaired);
        }
        return unpaired;
  }
}
