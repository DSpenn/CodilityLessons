function solution(S) {
  let count = 0;
  for (let i = 0; i < S.length; i++) {
    if (S[i] == "(") count++;
    else if (S[i] == ")") count--;
    if (count < 0) return 0
  }
  return count === 0 ? 1 : 0
}

//console.log(solution("(()(())())")); // 1
