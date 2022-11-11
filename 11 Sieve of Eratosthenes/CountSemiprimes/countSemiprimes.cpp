#include <math.h>
#include <vector>
int isSemiPrime(int nn) {
  int num = nn;
  int cnt = 0;
  int boundary = std::round(sqrt(num));
  // cout << "boundary " << boundary << endl;
  for (auto i = 2; cnt < 2 && i <= boundary; i++) {
    while (num % i == 0) {
      num /= i;
      cnt++;
    }
  }
  if (num > 1) cnt++;
  return cnt == 2;
}
// 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 6, 7, 8, 8, 8, 9, 10

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
  vector<int> semiPrime(N + 1);
  vector<int> output(P.size());
  int semiPCount = 0;
  for (auto y = 0; y <= N; y++) {
    if (isSemiPrime(y)) {
      semiPrime[y] = semiPCount + 1;
      semiPCount += 1;
    } else
      semiPrime[y] = semiPCount;
  }

  for (auto x = 0; x < P.size(); x++) {
    output[x] = semiPrime[Q[x]] - semiPrime[P[x] - 1];
  }
  return output;
}
