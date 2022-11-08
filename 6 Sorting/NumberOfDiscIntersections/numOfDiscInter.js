function solution(A) {
  let answer = 0;
  const a = A.map((v, i) => [i - v, i + v]);
  a.sort((a, b) => a[0] - b[0]);
  // [ -4, 6 ], [ -1, 1 ], [ 0, 4 ], [ 0, 8 ], [ 2, 4 ], [ 5, 5 ] ]
  for (let x = 0; x < a.length - 1; x += 1) {
    for (let y = x + 1; y < a.length; y += 1) {
      if (a[x][0] <= a[y][0] && a[x][1] >= a[y][0]) answer += 1;
      else break;
      if (answer > 10000000) return -1;
    }
  }

  return answer;
}

solution([1, 5, 2, 1, 4, 0]); //  11
