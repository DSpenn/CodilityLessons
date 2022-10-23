A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

function solution(S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S is made only of the characters "(" and/or ")".



Javascript 100% O(N)
```javascript
function solution(S) {
  let count = 0;
  for (let i = 0; i < S.length; i++) {
    if (S[i] == "(") count++;
    else if (S[i] == ")") count--;
    if (count < 0) return 0
  }
  return count === 0 ? 1 : 0
}

console.log(solution("(()(())())")); // 1

```

Java 100% O(N)
```java
class Solution {
  public int solution(String S) {
    int count = 0;
    for (int i = 0; i < S.length(); i++) {
      if (S.charAt(i) == '(') {
        count++;
        //System.out.println(i + " " + S.charAt(i));
      } else if (S.charAt(i) == ')') {
        count--;
        //System.out.println(i + " " + S.charAt(i));
      }
      if (count < 0)
        return 0;
    }
    return count == 0 ? 1 : 0;
  }
}

```