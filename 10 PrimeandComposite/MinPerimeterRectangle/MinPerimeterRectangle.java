// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
  public int solution(int N) {
    int i = 1;
    int perimeter=0;
    while ((i * i) <= N) {
      if (N % i == 0) {
        perimeter = 2 * (i + N / i);
      }
      i += 1;
    }
    return perimeter;
  }
}
