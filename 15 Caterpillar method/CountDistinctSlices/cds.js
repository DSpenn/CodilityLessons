function solution(M, A) {
  const LIMIT = 1000000000;
  const lastPos = [];
  let count = 0;
  let start = 0;

  if (A.length === 1) return 1;
  let i = 0;

  for (i = 0; i <= M; i += 1) {
    lastPos[i] = -1;
  }

  for (i = 0; i < A.length; i += 1) {
    const item = A[i];

    if (lastPos[item] + 1 > start) {
      start = lastPos[item] + 1;
    }

    lastPos[item] = i;
    count += i - start + 1;

    if (count > LIMIT) break;
  }

  return count > LIMIT ? LIMIT : count;
}


console.time('time');
console.log(solution(6,[3,4,5,5,2]));
console.timeEnd('time');
