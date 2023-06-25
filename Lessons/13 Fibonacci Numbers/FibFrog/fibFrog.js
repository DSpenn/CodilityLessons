function solution(A) {
  if (A.length <= 2) return 1;
  const fibArr = new Array(A.length + 2 > 30 ? 30 : A.length + 2);
  fibArr[0] = 1;
  fibArr[1] = 2;

  for (let i = 2; i < fibArr.length; i++) {
    fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
    if (fibArr[i] == A.length + 1) return 1;
  }

  const mins = new Array(A.length + 1);
  let k = 0;
  for (let i = 0; i < mins.length; i++) {
    if (i < A.length && A[i] == 0) {
      mins[i] = -1;
      continue;
    }
    let min = Number.MAX_SAFE_INTEGER;

    for (let j = fibArr.length - 1; j >= 0; j--) {
      k = i - fibArr[j];
      if (k < -1) continue;
      if (k == -1) {
        min = 1;
        break;
      }
      if (mins[k] < 0) continue;

      if (mins[k] + 1 < min) min = mins[k] + 1;
    }
    if (min != Number.MAX_SAFE_INTEGER) mins[i] = min;
    else mins[i] = -1;
  }

  return mins[A.length];
}

console.log(solution([0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0])); // 3
