import java.util.Arrays;
import java.util.Stack;

class Solution {
  public int solution(int[] A, int[] B) {
    if (A.length == 0) {
      return 0;
    }
    Stack<Integer> upstream = new Stack<Integer>();
    int eaten = 0;
    int fish = 0;

    for (int i = 0; i < A.length; i++) {
      if (B[i] == 1) {
        upstream.push(A[i]);
      } else {
        while (!upstream.empty()) {
          eaten += 1;
          fish = upstream.pop();
          if (fish > A[i]) {
            upstream.push(fish);
            break;
          }
        }
      }
    }
    return (A.length - eaten);
  }
}
