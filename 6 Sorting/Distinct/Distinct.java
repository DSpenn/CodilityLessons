import java.util.Arrays;
import java.util.Set; 
import java.util.HashSet; 

class Solution {
    public int solution(int[] A) {
      if(A.length == 0) { return 0; }

      Set<Integer> Set = new HashSet<>(); 
        for (int element : A) { 
          Set.add(element);
      }
      //System.out.println(Set.size());
      return Set.size();
      }
  }



/* class Solution { public int solution(int[] A); 
  {
        if(A.length == 0) { return 0; }

        int numOfDistinct = 1;
        Arrays.sort(A);
        
        for(int i=1; i< A.length; i++) {
            if(A[i] != A[i-1]) {
                numOfDistinct++;
            }
        }
        System.out.println(numOfDistinct);
        return numOfDistinct;
    }
}
 */