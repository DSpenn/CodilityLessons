import java.util.Arrays;

class Solution {
  public int[] solution(int[] A, int[] B) {
    int[] result = new int[A.length];
    int[] steps = new int[A.length + 1];
    steps[0] = 1;
    steps[1] = 1;

    int max = Arrays.stream(A).max().getAsInt();
    int maxB = Arrays.stream(B).max().getAsInt();

    int y = 1;
    while ((y += 1) <= max) {
      steps[y] = (steps[y - 1] + steps[y - 2]) % (int) Math.pow(2, maxB);
    }

    for (int x = 0; x < A.length; x += 1) {
      int div = (int) Math.pow(2, B[x]) - 1;
      result[x] = steps[A[x]] & div;
    }

    return result;
  }
}