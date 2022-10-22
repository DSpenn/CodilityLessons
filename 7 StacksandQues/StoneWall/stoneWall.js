function solution(H) {
  let outputSum = 0;
  let y = 0;
  const arr = [];

  for (let x = 0; x < H.length; x += 1) {
    while (y > 0 && arr[y - 1] > H[x]) {
      y -= 1;
    }
    if (y > 0 && arr[y - 1] === H[x]) {
      continue;
    } else {
      outputSum += 1;
      arr[y] = H[x];
      y += 1;
    }
  }
  return outputSum;
}
