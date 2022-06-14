function solution(A) {
  const a = [...new Set(A.map(Math.abs))];
  return a.length;
}
console.log(solution([-5, -3, -1, 0, 3, 6]));
