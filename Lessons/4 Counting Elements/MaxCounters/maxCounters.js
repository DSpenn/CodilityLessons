function solution(N, A) {
  const counters = new Array(N).fill(0);
  let max = 0;
  const len = A.length;
  let lastOpp = 0;
  for (let k = 0; k < len; k += 1) {          
    if (A[k] === N + 1) {
      if (lastOpp == 'max') {
        console.log('max')
        continue;
      } 
      for (let i = 0; i < N; i += 1) {
        counters[i] = max;
      }
      lastOpp = 'max';
    } else {
       counters[A[k] - 1] += 1; 
        if (counters[A[k] - 1] > max) {
            max = counters[A[k] - 1];
        }
        lastOpp = 'increase';
      } 
  }
  return counters;
}
console.log(solution(5, [3, 4, 4, 6, 1, 4, 4]));
console.log(solution(5, [3, 4, 4, 6, 6, 1, 4, 4]));

for (let y = 0; y < 10; y++) {
  const z = 1000000;
  console.time(`${z}`);
  const test1 = (Array.from({ length: z }, () => Math.floor(Math.random() * z)));
  solution(z,test1);
  console.timeEnd(`${z}`);
  }
