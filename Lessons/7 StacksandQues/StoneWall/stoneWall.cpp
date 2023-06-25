#include <vector>
int solution(vector<int> &H) {
  int outputSum = 0;
  vector<int> v(H.size());
  int y = 0;
  for (unsigned int x = 0; x < H.size(); x += 1) {
    while (y > 0 && v.at(y - 1) > H[x]) {
      y -= 1;
    }
    if (y > 0 && v[y - 1] == H[x]) {
      continue;
    } else {
      outputSum += 1;
      v[y] = H[x];
      y += 1;
    }
  }
  return outputSum;
}