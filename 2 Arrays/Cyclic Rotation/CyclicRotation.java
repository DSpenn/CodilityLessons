class Solution {
  public int[] solution(int[] A, int K) {
    int[] result = new int[A.length];

    for (int i = 0; i < result.length; i++) {
      int newPosition = (i + K) % result.length;
      result[newPosition] = A[i];
    }
  
    return result;
  }
}
