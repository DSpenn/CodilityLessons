https://app.codility.com/demo/results/training88UXTH-5D5/
function solution(S, P, Q) {
  const arr = [];
  const scores = [];
  const maxLen = S.length;

  const letters = S.split('')
  console.log('letters', letters);

  
  console.log('length/ maxLen', S.length);

  for (let x = 0; x < P.length; x += 1) {
    if (P[x] == Q[x]) {
      arr.push(S.charAt(P[x]));
    } else {
      console.log('S.substring(P[x], Q[x + 1]', S.substring(P[x], Q[x]+1));
      arr.push(S.substring(P[x], Q[x]+1));
    }
  }
console.log('arr', arr);

  for (let i = 0; i < arr.length; i += 1) {
    if (arr[i].includes('A') && arr[i].includes('C') && arr[i].includes('G') && arr[i].includes('T')) {
      scores.push(1);
    } else if (arr[i].includes('A')) {
      scores.push(1);
    } else if (arr[i].includes('C')) {
      scores.push(2);
    } else if (arr[i].includes('G')) {
      scores.push(3);
    } else if (arr[i].includes('T')) {
      scores.push(4);
    }
  }
  return scores;
}

//console.log(solution('CAGCCTA', [2, 5, 0], [4, 5, 6])); // hould return the values [2, 4, 1]
console.log(solution('TC', [0, 0, 1], [0, 1, 1])); // [4, 2, 2]).
