import java.util.Stack;

class Solution {
  public int solution(int[] H) {
    int outputSum = 0;
    Stack<Integer> stk = new Stack<>();
    for (int x = 0; x < H.length; x += 1) {
      while (!stk.isEmpty() && stk.peek() > H[x]) {
        stk.pop();
      }
      if (stk.isEmpty()) {
        outputSum++;
        stk.push(H[x]);
      } else if (stk.peek() < H[x]) {
        outputSum++;
        stk.push(H[x]);
      }
    }
    return outputSum;
  }
}
