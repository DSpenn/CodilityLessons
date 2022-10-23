function solution(A) {
  var sum = 0
  var max = A[0]
  var maxCell = A[0]
  for (a of A) {
    sum = Math.max(0, sum + a)
    max = Math.max(max, sum)
    maxCell = Math.max(maxCell, a)
  }
  if (max == 0)
    return maxCell
  return max
}

solution([3, 2, -6, 4, 0]);
