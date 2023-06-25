function solution(A) {
  const set = new Set(A);
  let i = 1;
  while (set.has(i)) i += 1;
  return i;
}


console.log(solution([1, 2, 3])); // should return 4
console.log(solution([1, 2, 3,2,1]));
console.log(solution([-1, -3])); //should return 1