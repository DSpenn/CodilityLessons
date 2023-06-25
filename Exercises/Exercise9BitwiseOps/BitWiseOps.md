

javascript 100% O(log(A+B+C))

```javascript
function solution(A, B, C) {
  let a = 0; //possibilities of A
  let b = 0;
  let c = 0;

  let nAorB = 0; // (possibilities of A or B)
  let nAorC = 0;
  let nBorC = 0;
  let nAorBorC = 0;

  const AorB = A | B;      //The bitwise OR (|) operator returns a 1 in each bit position for which the corresponding bits of either or both operands are 1s. 
  //console.log(AorB); // 1073741759
  const AorC = A | C;
  //console.log(AorC); // 1073741823
  const BorC = B | C;
  //console.log(BorC); // 1073741695
  const AorBorC = A | B | C;
  //console.log(AorBorC); // 1073741823

  // & 0x01 will perform a bitwise AND of the variable write_data and a 1.  This will give you the value of the least significant bit of the variable.
  // shift right '>>' by i and check if the rightmost digit is 0
  for (let i = 0; i < 30; i++) {
    if (((A >> i) & 0x01) == 0) a++;
    if (((B >> i) & 0x01) == 0) b++;
    if (((C >> i) & 0x01) == 0) c++;

    if (((AorB >> i) & 0x01) == 0) nAorB++;
    if (((AorC >> i) & 0x01) == 0) nAorC++;
    if (((BorC >> i) & 0x01) == 0) nBorC++;

    if (((AorBorC >> i) & 0x01) == 0) nAorBorC++;
  }

  const result =
    (1 << a) -
    (1 << nAorB) -
    (1 << nAorC) -
    (1 << nBorC) +
    (1 << b) +
    (1 << c) +
    (1 << nAorBorC);

  return result;
}

console.time('time');
console.log(solution(1073741727, 1073741631, 1073741679), ' = ', 8);
console.log(solution(0, 0, 0), ' = ', '1073741824 or 2**30');
console.log(solution(1023, 8184, 65472), ' = ', 2883584);
console.timeEnd('time');




```