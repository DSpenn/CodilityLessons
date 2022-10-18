Write a function:

function solution(A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

```javascript
function solution(A) {
  const set = new Set(A);
  let i = 1;
  while (set.has(i)) i += 1;
  return i;
}

console.log(solution([1, 2, 3])); // should return 4
console.log(solution([1, 2, 3,2,1]));
console.log(solution([-1, -3])); //should return 1

```


Java
```java
class Solution {
    public int solution(int[] A) {
        if(A.length ==0){
            return 1;
        }
        Set<Integer> set = new HashSet<Integer>();
        for(int i=0; i< A.length; i++){
            set.add(A[i]);
        }
        int i = 1;
        while (set.contains(i)) i++;

        return i;
    }
}
```


C++ 100% O(N) or O(N * log(N))
```C++
#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> &A) {
    set<int> s;
    for (int x : A) { 
        s.insert(x);
    }
    int i = 1;
    while (s.count(i)) i++;
    return i;
}
```