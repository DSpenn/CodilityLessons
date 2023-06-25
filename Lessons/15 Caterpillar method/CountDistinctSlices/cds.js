function solution(M, A) {
  if (A.length === 1) return 1;
  const LIMIT = 1000000000;
  let count = 0;
  let start = 0;
  const lastPos = new Array(M + 1).fill(-1);

  for (let i = 0; i < A.length; i += 1) {
    if (lastPos[A[i]] + 1 > start) {
      start = lastPos[A[i]] + 1;
    }
    lastPos[A[i]] = i;
    count += i - start + 1;

    if (count > LIMIT) break;
  }
  return count > LIMIT ? LIMIT : count;
}

/* 
console.time('time');
console.log(solution(6,[3,4,5,5,2]));
console.timeEnd('time'); */