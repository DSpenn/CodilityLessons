class Solution {
  public int solution(int K, int[] A) {
    if (K == 1)
      return A.length;

    int count = 0;
    int sum = 0;

    for (int i = 0; i < A.length; i += 1) {
      sum += A[i];
      if (sum >= K) {
        sum = 0;
        count += 1;
      }
    }
    return count;
  }
}