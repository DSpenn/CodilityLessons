function solution(A) {
  if (A.length === 1) return 0;
  let maxRep = 1;
  let maxIndex = -1;
  let obj = {};
  for (let i = 0; i < A.length; i++) {
    if (obj.hasOwnProperty(A[i])) {
      obj[A[i]][0]++;
      if (obj[A[i]][0] > maxRep && obj[A[i]][0] > A.length / 2) {
        maxRep = obj[A[i]][0];
        maxIndex = obj[A[i]][1];
      }
    } else {
      obj[A[i]] = new Array();
      obj[A[i]][0] = 1
      obj[A[i]][1] = i
    }
  }
  let equiLeader = 0;
  let x = 0;
  for (let i = 0; i < A.length; i++) {
    if (x > (Math.floor(i / 2)) && (maxRep - x > Math.floor((A.length - i) / 2))) {
      equiLeader++;
    }
    if (A[i] === A[maxIndex]) x++;
  }
  return equiLeader
}