An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

function solution(A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].


```javascript
function solution(A) {
  const set = new Set(A);
  let i = 1;
  while (set.has(i)) i +=1;
  return i;
}

console.log(solution([2, 3, 1, 5]));

```


Java 100 % O(N) or O(N * log(N))
```java
import java.util.*;

class Solution {
    public int solution(int[] A) {
        Set<Integer> set = new HashSet<Integer>();
        for(int i=0; i< A.length; i++){
            set.add(A[i]);
          }
        int i = 1;
        while (set.contains(i)) i +=1;

        return i;
    }
}
```


C++ 100% O(N) or O(N * log(N))
```C++
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
  set<int> mySet;
  for(int i=0; i<A.size();i++) {
    if(mySet.count(A[i])==0)
      mySet.insert(A[i]);
    }
  int y = 1;
  while (mySet.count(y)) y +=1;
  return y;
  }
```