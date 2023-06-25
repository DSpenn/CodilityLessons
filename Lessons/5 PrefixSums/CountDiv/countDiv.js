function solution(A, B, K) {
  return (Math.floor(B / K) - Math.floor((A - 1) / K));
}
console.log(solution(6, 11, 2)) //should return 3. 3 numbers divisible by 2 
