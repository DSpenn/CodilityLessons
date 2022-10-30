
class Solution {
  public int solution(int N) {
    int maxGap = 0;
    int currGap = 0;
    boolean isInGap = false;
    while (N > 0) {
      if (N % 2 == 1 || N == 1) {
        maxGap = maxGap < currGap ? currGap : maxGap;
        currGap = 0;
        isInGap = true;
      } else if (isInGap) {
        currGap++;
      }
      N /= 2;
    }
    return maxGap;
  }
}
