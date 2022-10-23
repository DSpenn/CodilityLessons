class Solution {
  public int solution(int[] A) {
    int sum = 0;
    int max = A[0];
    int maxCell = A[0];
    for (int a : A) {
      sum = Math.max(0, sum + a);
      max = Math.max(max, sum);
      maxCell = Math.max(maxCell, a);
    }
    if (max == 0)
      return maxCell;
    return max;
  }
}
