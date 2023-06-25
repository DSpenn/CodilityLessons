function solution(S) {
  const a = [];
  for (let i = 0; i < S.length; i += 1) {
    const c = S[i];

    if (c === '(' || c === '{' || c === '[')
      a.push(c);

    if (c === ')') {
      if (a.pop() !== '(')
        return 0;
    }

    if (c === '}') {
      if (a.pop() !== '{')
        return 0;
    }

    if (c === ']') {
      if (a.pop() !== '[')
        return 0;
    }
  }

  if (a.length !== 0) return 0;
  if (a.length === 0) return 1;
}

console.log(solution('{{{{')); // 0
console.log(solution('{[()()]}')); // 1
console.log(solution('([)()]')); // 0
