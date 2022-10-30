We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:

  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0


There are eleven (unordered) pairs of discs that intersect, namely:

discs 1 and 4 intersect, and both intersect with all the other discs;
disc 2 also intersects with discs 0 and 3.
Write a function:

function solution(A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2,147,483,647].



Javascript 100 % O(N*log(N)) or O(N)
```javascript
function solution(A) {
  let answer = 0;
  const arr = A.map((v, i) => [i - v, i + v]);
  arr.sort((a, b) => a[0] - b[0]);
  for (let x = 0; x < arr.length; x += 1) {
    for (let y = x + 1; y < arr.length; y += 1) {
      if (arr[x][0] <= arr[y][0] && arr[x][1] >= arr[y][0]) answer += 1;
      else break;
      if (answer > 10000000) return -1;
    }
  }
  return answer;
}

solution([1, 5, 2, 1, 4, 0]); //  11
```




C++ 100% O(N*log(N)) or O(N)
```c++
#include <algorithm>
#include <vector>
int solution(vector<int> &A) {
  vector<long> range1(A.size());
  vector<long> range2(A.size());
  for (size_t i = 0; i < A.size(); i++) {
    range1[i] = i - A[i];
    range2[i] = i + A[i];
  }
  sort(range1.begin(), range1.end());
  sort(range2.begin(), range2.end());

  int result = 0;
  int j = 0, k = 0;
  while (j < A.size()) {
    while (k < A.size() && range2[j] >= range1[k]) k++;
    result += k - j - 1;
    j++;
    if (result > 10000000) return -1;
  }
  return result;
}
```