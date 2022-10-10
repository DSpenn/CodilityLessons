import java.util.Arrays;


class Solution { public int solution(int[] A); 
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