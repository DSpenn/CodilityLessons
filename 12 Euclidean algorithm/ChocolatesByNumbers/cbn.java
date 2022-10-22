class Solution {
  public int solution(int N, int M) {
    return N / (gcd(N, M));
  }

  public static int gcd(int n, int m) {
    if (n % m == 0)
      return m;
    else
      return gcd(m, n % m);
  }
}
