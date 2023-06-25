class Solution {
  public int solution(int[] A) {
    int[] sumsL = new int[A.length];
    int[] sumsR = new int[A.length];
    int max = 0;
    for (int left = 1, right = A.length - 2; right >= 2;
         left += 1, right -= 1) {
      sumsL[left] = Math.max(0, sumsL[left - 1] + A[left]);
      sumsR[right] = Math.max(0, sumsR[right + 1] + A[right]);
    }
    max = sumsL[0] + sumsR[2];
    for (int x = 2; x < A.length - 1; x += 1) {
      max = Math.max(max, sumsL[x - 1] + sumsR[x + 1]);
    }
    return max;
  }
}
