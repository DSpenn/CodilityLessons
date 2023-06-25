class Solution {
  public int solution(int[] A) {
    int totalSum = 0;
    int min = Integer.MAX_VALUE;

    for (int i : A) totalSum += i;

    //System.out.println("total sum: " + totalSum);
    for (int i = 0; i < A.length - 1; i++) {
      totalSum -= 2 * A[i];
      if (min > Math.abs(totalSum)) {
        min = Math.abs(totalSum);
      }
    }
    //System.out.println("min " + min);
    return min;
  }
}