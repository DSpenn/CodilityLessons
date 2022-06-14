function solution(A) {

  A.sort((a, b) => a - b);
  const uniqueCheck = new Set(A);
  //const unique = [...new Set(A)];
  //if (unique.length !== A.length) {
  if (uniqueCheck.size !== A.length) {
      return 0;
  }

  for (var i =0; i < A.length; i += 1) {
      if(A[i] !== (i + 1)) {
          return 0;
      }
  }
  return 1;
}

solution([4, 1, 3, 2, 5, 6, 7, 11, 9, 10, 8]);
solution([4, 1, 3]);
solution([4, 1, 3 , 3]);
