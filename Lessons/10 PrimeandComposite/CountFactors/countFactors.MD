A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.

For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).

Write a function:

function solution(N);

that, given a positive integer N, returns the number of its factors.

For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
```javascript
function solution(N) {
  let i = 0;
  let result = 0;

  while (i * i <= N) {
      if (N % i === 0) {

          if (i === N / i) {
            result += 1;
          } else {
            result += 2;
          }
      }
      i += 1;
  }
  return result;
}

console.log(solution(24));

```


Java 100%
```Java
class Solution {
  public int solution(int N) {
    long i = 1;
    long result = 0;
    while (i * i <= N) {
      if (N % i == 0) {
        if (N / i == i) {
          result++;
        } else {
          result += 2;
        }
      }
      i++;
    }
    return (int) result;
  }
}
```


C++ 100% O(sqrt(N))
```C++
#include <limits.h>
#include <cmath>

int solution(int N) {
  int count = 0;
  for (int i = 1; i <= sqrt(N); i++) {
    if (N % i == 0) {
      if (N / i == i) {
        count++;
      } else {
        count = count + 2;
      }
    }
  }
  return count;
}
```