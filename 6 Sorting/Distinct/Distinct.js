function solution(A) {
  const distinctSet = new Set(A);
  return distinctSet.size;
}
console.log(solution([2,1,1,2,3,1]));
