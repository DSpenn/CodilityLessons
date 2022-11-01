#include <map>
#include <vector>

int solution(vector<int> &A) {
  pair<int, int> maxPair;
  map<int, int> freq;
  vector<int> B;
  for (int x : A) {
    freq[x]++;
  }

  int maxValue = 0;
  for (const auto &entry : freq) {
    if (maxValue < entry.second) {
      maxValue = entry.second;
      maxPair = entry;
    }
  }

  if (maxValue <= (A.size() / 2)) return -1;
  
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == maxPair.first) {
      B.push_back(i);
    }
  }
  return B[0];
}
