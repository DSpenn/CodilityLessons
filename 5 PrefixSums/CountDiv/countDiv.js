function solution(A, B, K)
{
  console.log('Math.floor(B/K)',Math.floor(B/K));
  console.log('Math.floor((A-1)/K', Math.floor((A-1)/K));
  return (Math.floor(B/K) - Math.floor((A-1)/K));
}

console.log(solution(6,11,2)) //should return 3. 3 numbers divisible by 2 
// with range 6..11 // 6,8,10