A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

        S is empty;
        S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
        S has the form "VW" where V and W are properly nested strings.

For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

    function solution(S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..200,000];
        string S is made only of the following characters: "(", "{", "[", "]", "}" and/or ")".





Javascript 100% O(N)
```javascript
function solution(S) {
  const a = [];
  for (let i = 0; i < S.length; i += 1) {
    const c = S[i];

    if (c === '(' || c === '{' || c === '[')
      a.push(c);

    if (c === ')') {
      if (a.pop() !== '(')
        return 0;
    }

    if (c === '}') {
      if (a.pop() !== '{')
        return 0;
    }

    if (c === ']') {
      if (a.pop() !== '[')
        return 0;
    }
  }

  if (a.length !== 0) return 0;
  if (a.length === 0) return 1;
}

console.log(solution('{{{{')); // 0
console.log(solution('{[()()]}')); // 1
console.log(solution('([)()]')); // 0

```


Java 100% O(N)
```java
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
```
C++ 100% O(N)
```c++
#include <stack>
int solution(string &S) {
  if (S.size() == 0) return 1;  // if input empty
  if (S.size() % 2) return 0;   // if odd input cant be properly nested

  stack<char> stk;

  for (auto &s : S)
    if (s == '(' or s == '[' or s == '{')
      stk.push(s);
    else if (stk.size() == 0)
      return false;
    else if (s == ')' and stk.top() != '(')
      return false;
    else if (s == ']' and stk.top() != '[')
      return false;
    else if (s == '}' and stk.top() != '{')
      return false;
    else
      stk.pop();

  return stk.size() == 0;
}
```