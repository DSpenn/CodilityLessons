function solution(A) {
  const distinctSet = new Set(A);
  console.log(distinctSet);

  return distinctSet.size;
}

console.log(solution([2,1,1,2,3,1])); //the function should return 3, 
//because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
