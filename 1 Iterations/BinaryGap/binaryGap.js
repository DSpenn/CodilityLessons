function solution(N) {
    const a = N.toString(2).split("");
    const counts = new Set();
    let zero = 0;
    for (let y = 0; y < a.length; y += 1) {
      if (a[y] == 0) zero++;
      if (a[y] == 1) {
        counts.add(zero);
        zero = 0;
      }
    }
    return (counts.size == 0) ? 0 : Math.max(...counts);
  }

  console.log(solution(1041)); // 5
  console.log(solution(32)); // 0
