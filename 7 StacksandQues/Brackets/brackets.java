import java.util.Stack;
class Solution {
  public int solution(String S) {
    if (S.length() == 0)
      return 1;

    Stack<Character> stk = new Stack<>();

    for (char c : S.toCharArray()) {
      if (c == '(' || c == '{' || c == '[') {
        stk.push(c);
      }
      if (stk.isEmpty())
        return 0;

      if (c == ')') {
        if (stk.pop() != '(') return 0;
      }
      if (c == '}') {
        if (stk.pop() != '{') return 0;
      }
      if (c == ']') {
        if (stk.pop() != '[') return 0;
      }
    }
    if (!stk.isEmpty()) {
      return 0;
    } else {
      return 1;
    }
  }
}