You are given an array A consisting of N integers.

For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. We say that these elements are non-divisors.

For example, consider integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
For the following elements:

A[0] = 3, the non-divisors are: 2, 6,
A[1] = 1, the non-divisors are: 3, 2, 3, 6,
A[2] = 2, the non-divisors are: 3, 3, 6,
A[3] = 3, the non-divisors are: 2, 6,
A[4] = 6, there aren't any non-divisors.
Write a function:

function solution(A);

that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

Result array should be returned as an array of integers.

For example, given:

    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
the function should return [2, 4, 3, 2, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..2 * N].


javascript 100% O(N * log(N))
```javascript
function solution(A) {
  const counters = Array(A.length * 2 + 1).fill(0);
  for (let x = 0; x < A.length; x += 1) counters[A[x]] += 1;

  return A.map((number) => {
    let nonDivisor = A.length;
    for (let i = 1; i * i <= number; i += 1) {
      if (number % i !== 0) continue;
      nonDivisor -= counters[i];
      if (i * i !== number) nonDivisor -= counters[number / i];
    }
    return nonDivisor;
  });
}

solution([3, 1, 2, 3, 6]); // [2, 4, 3, 2, 0]

```