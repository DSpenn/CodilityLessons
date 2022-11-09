class Solution {
  public int solution(int[] A, int[] B) {
    if (A.length == 0) return A.length;
    int count = 1;
    int ending = B[0];
    for (int x = 1; x < B.length; x += 1) {
      if (A[x] > ending) {
        ending = B[x];
        count += 1;
      }
    }
    return count;
  }
}