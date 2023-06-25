function solution(X, A) {
  const leaves = new Set();

  for (let i = 0; i < A.length; i++) {
      leaves.add(A[i]);
      if (leaves.size === X) return i;
  }
  
 return -1;
}

console.log(solution(5,[1,3,1,4,2,3,5,4]));
// O(n)