#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  return A.size();
}


/* 
#include <set>

int solution(vector<int> &A) {
  set<int> mySet;
  for (int i = 0; i < A.size(); i++) {
    if (mySet.count(A[i]) == 0) mySet.insert(A[i]);
  }
  return mySet.size();
}
 */
