
import java.util.Arrays;

class Solution {
    public int solution(int[] A) {
        Arrays.sort(A);
        int x = Math.max(A[A.length - 1] * A[A.length - 2] * A[A.length - 3], A[A.length - 1] * A[0] * A[1]);
        return x;
    }
}
