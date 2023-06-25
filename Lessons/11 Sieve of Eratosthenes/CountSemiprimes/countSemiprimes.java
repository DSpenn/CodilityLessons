import java.util.Arrays;

class Solution {
  public int[] solution(int N, int[] P, int[] Q) {
    int[] semiPrime = new int[N + 1];
    int[] output = new int[P.length];
    int semiPCount = 0;
    for (int y = 0; y <= N; y++) {
      if (isSemiPrime(y)) {
        semiPrime[y] = semiPCount + 1;
        semiPCount += 1;
      } else
        semiPrime[y] = semiPCount;
    }

    for (int x = 0; x < P.length; x++) {
      output[x] = semiPrime[Q[x]] - semiPrime[P[x] - 1];
    }
    return output;
  }

  boolean isSemiPrime(int nn) {
    int num = nn;
    int cnt = 0;
    int boundary = (int) Math.sqrt(num);
    for (int i = 2; cnt < 2 && i <= boundary; i++) {
      while (num % i == 0) {
        num /= i;
        cnt++;
      }
    }
    if (num > 1)
      cnt++;
    return cnt == 2;
  }
}
