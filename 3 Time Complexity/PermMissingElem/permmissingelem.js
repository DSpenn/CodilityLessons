function solution(A) {
  const set = new Set(A);
  let i = 1;
  while (set.has(i)) i +=1;
  return i;
}

console.log(solution([2, 3, 1, 5]));