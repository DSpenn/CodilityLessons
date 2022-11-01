function solution(A) {
  const count = {};
  const indices = [];
  A.forEach(e => { count[e] = (count[e] || 0) + 1 });
  const domin = Math.max(...Object.values(count));
  if (domin <= (A.length / 2)) return -1;
  let key = parseInt(Object.keys(count).find(k => count[k] === domin));
  let idx = A.indexOf(key);
  while (idx != -1) {
    indices.push(idx);
    idx = A.indexOf(key, idx + 1);
  }
  return indices[0];
}
