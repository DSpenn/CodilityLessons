int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int solution(vector<int> &A, vector<int> &B) {
  int resCount = 0;
  for (unsigned int i = 0; i < A.size(); i += 1) {
    int a = A[i];
    int b = B[i];
    int d = gcd(a, b);
    int c = 0;

    while (c != 1) {
      c = gcd(a, d);
      a /= c;
    }

    c = 0;

    while (c != 1) {
      c = gcd(b, d);
      b /= c;
    }

    if (a == 1 && b == 1) {
      resCount += 1;
    }
  }
  return resCount;
}
