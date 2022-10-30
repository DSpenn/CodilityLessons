A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

function solution(N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

javascript 100%
```javascript
function solution(N) {
    const a = N.toString(2).split("");
    const counts = new Set();
    let zero = 0;
    for (let y = 0; y < a.length; y += 1) {
      if (a[y] == 0) zero++;
      if (a[y] == 1) {
        counts.add(zero);
        zero = 0;
      }
    }
    return (counts.size == 0) ? 0 : Math.max(...counts);
  }

  console.log(solution(1041)); // 5
  console.log(solution(32)); // 0

```

Java 100%
```java

class Solution {
  public int solution(int N) {
    int maxGap = 0;
    int currGap = 0;
    boolean isInGap = false;
    while (N > 0) {
      if (N % 2 == 1 || N == 1) {
        maxGap = maxGap < currGap ? currGap : maxGap;
        currGap = 0;
        isInGap = true;
      } else if (isInGap) {
        currGap++;
      }
      N /= 2;
    }
    return maxGap;
  }
}
```

C++ 100%
```c++
#include <set>
#include <string>
#include <vector>
int solution(int N) {
  int bin;
  vector<int> b;
  set<int> counts;
  int zero = 0;
  bool gap = false;

  while (N > 0) {
    bin = N % 2;
    b.push_back(bin);
    N /= 2;
  }

  // for (int x : b) { cout << x; } print binary representation of number vector

  for (unsigned int y = 0; y < b.size(); y += 1) {
    if (b.at(y) == 0 && gap == true) {
      zero++;
    }
    if (b.at(y) == 1) {
      gap = true;
      counts.insert(zero);
      zero = 0;
    }
  }
  // for (int i : counts) { cout << i << ' '; }  print gap counts set
  return (counts.size() == 0) ? 0 : *counts.rbegin(); 
}
```