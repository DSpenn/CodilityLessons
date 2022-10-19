#include <set>

int solution(vector<int> &A) {
  set<int> mySet;
  for (int i = 0; i < A.size(); i++) {
    if (mySet.count(A[i]) == 0) mySet.insert(A[i]);
  }
  return mySet.size();
}
