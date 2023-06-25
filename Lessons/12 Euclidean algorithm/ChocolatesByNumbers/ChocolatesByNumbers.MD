Two positive integers N and M are given. Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.

You start to eat the chocolates. After eating a chocolate you leave only a wrapper.

You begin with eating chocolate number 0. Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.

More precisely, if you ate chocolate number X, then you will next eat the chocolate with number (X + M) modulo N (remainder of division).

You stop eating when you encounter an empty wrapper.

For example, given integers N = 10 and M = 4. You will eat the following chocolates: 0, 4, 8, 2, 6.

The goal is to count the number of chocolates that you will eat, following the above rules.

Write a function:

function solution(N, M);

that, given two positive integers N and M, returns the number of chocolates that you will eat.

For example, given integers N = 10 and M = 4. the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..1,000,000,000].


javascript O(log(N + M)) 
```javascript
function solution(N, M) { // Integer N represents the number of chocolates
  if (N === 1) return 1;
  if (M === 1) return N;
  const gcd = (n, m) => (m === 0 ? n : gcd(m, n % m));
  return N / gcd(N, M);
}
console.time('time');
solution(10, 4); // 5 eating 0, 4, 8, 2, 6
solution(415633212, 234332);
console.timeEnd('time');

```

Java 100% O(log(N + M))
```java
class Solution {
  public int solution(int N, int M) {
    return N / (gcd(N, M));
  }

  public static int gcd(int n, int m) {
    if (n % m == 0)
      return m;
    else
      return gcd(m, n % m);
  }
}
```


C++ 100% O(log(N + M))
```C++
long long int gcd(int n, int m) {
    if (n % m == 0)
      return m;
    else
      return gcd(m, n % m);
  }

int solution(int N, int M) {
  return N / (gcd(N, M));
}

```