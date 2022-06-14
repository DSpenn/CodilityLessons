function solution(A)
{
  A.sort((a, b) => a - b);

  for (let x = 0; x < (A.length-2); x++) {
    const p = A[x];
    const q = A[x+1];
    const r = A[x+2];

    if ((0 <= p < q < r < A.length) && (p + q) > r && (q + r) > p && (r + p) > q)
      return 1
    
  }
  return 0;
}

//console.log(solution([10,2,5,1,8,20]));
console.log(solution([10, 50, 5, 1]));
