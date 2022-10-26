
class Solution {
  public int solution(int N) {
    int maxGap = 0;
    int currGap = 0;
    boolean isInGap = false;
    while (N > 0) {
      if (N % 2 == 1 || N == 1) {
        // System.out.println("N: " + N);
        maxGap = maxGap < currGap ? currGap : maxGap;
        // System.out.println("maxGap: " + maxGap);
        currGap = 0;
        isInGap = true;
      } else if (isInGap) {
        currGap++;
        // System.out.println("currGap: " + currGap);
      }
      N /= 2;
    }
    return maxGap;
  }
}
