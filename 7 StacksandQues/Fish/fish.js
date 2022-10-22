function solution(A, B) {
  let upstream = [];
  let eaten = 0;
  let fishCount = 0;

  for (let i in A) {
    if (B[i] === 1) {
      upstream.push(A[i]);
    } else {
      while (upstream.length) {
        eaten += 1;
        const fish = upstream.pop();
        if (fish > A[i]) {
          upstream.push(fish);
          break;
        }
      }
    }
  }

  return A.length - eaten;
}

console.log(solution([4,4,2,1,5],[0,1,0,0,0])); // returns 2, 
