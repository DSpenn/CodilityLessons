function solution(A, B, C) {
  if (A === 0 || B === 0 || C === 0) return 2 ** 30;

  let a = 0; //possibilities of A
  let b = 0;
  let c = 0;
  let nAorB = 0; // (possibilities of A or B)
  let nAorC = 0;
  let nBorC = 0;
  let nAorBorC = 0;

  //The bitwise OR (|) operator returns a 1 in each bit position for which the corresponding bits of either or both operands are 1s.
  const AorB = A | B;
  //console.log(AorB); // 1073741759
  const AorC = A | C;
  //console.log(AorC); // 1073741823
  const BorC = B | C;
  //console.log(BorC); // 1073741695
  const AorBorC = A | B | C;
  //console.log(AorBorC); // 1073741823

  // x & 1 will perform a bitwise AND of the variable x and a 1. 
  // shift right '>>' by i and check if the rightmost digit is 0,  count++ 
  for (let i = 0; i < 30; i++) {

    // & 0x01 same as & 1 
    if (((A >> i) & 1) == 0) a++;
    if (((B >> i) & 1) == 0) b++;
    if (((C >> i) & 1) == 0) c++;

    if (((AorB >> i) & 1) == 0) nAorB++;
    if (((AorC >> i) & 1) == 0) nAorC++;
    if (((BorC >> i) & 1) == 0) nBorC++;

    if (((AorBorC >> i) & 1) == 0) nAorBorC++;
  }

  console.log("a:", a,  "b:", b, "c:", c, "nAorB:", nAorB, "nAorC:", nAorC, "nBorC:", nBorC, "nAorBorC:", nAorBorC);
  //a:2 b:2 c:2 nAorB:1 nAorC:0 nBorC:1 nAorBorC:0
  //(1 << a) = 4 , (1 << nAorB) = 2 , (1 << nAorBorC) = 1

  const result = (1 << a) + (1 << b) + (1 << c) -
    (1 << nAorB) - (1 << nAorC) - (1 << nBorC)
    + (1 << nAorBorC);
  // 4 + 4 + 4 - 2 - 1 - 2 + 1

  //a: 20 b: 20 c: 20 nAorB: 17 nAorC: 14 nBorC: 17 nAorBorC: 14
  // alternative way to get result
  //const result = (1 << a) - (1 << nAorB) - (1 << nAorC) - (1 << nBorC) + (1 << b) + (1 << c) + (1 << nAorBorC);
  return result;
}

//console.time("time");
//console.log(solution(1073741727, 1073741631, 1073741679), " = ", 8);
//console.log(solution(0, 0, 0), ' = 1073741824 or 2**30');
console.log(solution(1023, 8184, 65472), ' = ', 2883584);
//console.timeEnd("time"); //74672.23 ops/s ± 0.76%



/* 
alternative way to get 0 count
let aa = 0;
let AA = A;
while (AA != 0) {
  if (AA % 2 == 0) aa++;
  AA = Math.floor(AA / 2);
}
console.log(aa); 
*/