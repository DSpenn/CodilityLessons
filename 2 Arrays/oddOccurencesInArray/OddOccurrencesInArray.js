function solution(A)
{
  A.sort((a, b) => a - b);
  for (let i = 0; i < A.length; i+=2) {
    if(A[i] !== A[i+1]) return A[i];
  }
  return 0;

}

console.log(solution([9,3,9,3,9,7,9,12]));
