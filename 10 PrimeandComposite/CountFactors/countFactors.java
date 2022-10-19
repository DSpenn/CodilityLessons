class Solution {
  public int solution(int N) {
    long i = 1;
    long result = 0;
    while (i * i <= N) {
      if (N % i == 0) {
        if (N / i == i) {
          result++;
        } else {
          result += 2;
        }
      }
      i++;
    }
    return (int) result;
  }
}