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
  //console.log(answer);
  return answer;
}

solution([1, 5, 2, 1, 4, 0]); //  11
