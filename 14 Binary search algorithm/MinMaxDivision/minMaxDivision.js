function solution(K, M, A) {
  let begin = Math.max(...A);
  let end = A.reduce((acc, i) => acc + i, 0); // sum
  //let largeSum = begin + M + 1; // The large sum is the maximal sum of any block.
  let result = 0;
  while (begin <= end) {
    const mid = Math.floor((begin + end) / 2);

    let currentSum = 0;
    let blocks = 1;

    for (let i = 0; i < A.length; i++) {
      if (currentSum + A[i] > mid) {
        blocks++;
        currentSum = A[i];
        if (blocks > K) { break; }
      } else {
        currentSum += A[i];
      }
    }
    if (blocks > K) {
      begin = mid + 1;
    } else {
      result = mid;
      end = mid - 1;
    }
}
return result;
}
//console.log(solution(3, 5, [2, 1, 5, 1, 2, 2, 2]));
