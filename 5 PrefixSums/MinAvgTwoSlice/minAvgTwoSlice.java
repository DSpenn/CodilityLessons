class Solution {
  public int solution(int[] A) {
    int output = 0;
    double avg = 0;
    double minAvg = (A[0] + A[1]) / 2;
    for (int i = 2; i < A.length; i += 1) {
      avg = (double) (A[i - 2] + A[i - 1] + A[i]) / 3;
      if (minAvg > avg) {
        minAvg = avg;
        output = i - 2;
      }
      avg = (double) (A[i - 1] + A[i]) / 2;
      if (minAvg > avg) {
        minAvg = avg;
        output = i - 1;
      }
    }
    return output;
  }
}