#include <stack>
int solution(vector<int> &A, vector<int> &B) {
  stack<int> upstream;
  int eaten = 0;
  int fish=0;
  for (auto i = 0; i < A.size(); i++) {
    if (B[i] == 1) {
      upstream.push(A[i]);
    } else {
      while (upstream.size() > 0) {
        eaten += 1;
        fish = upstream.top();
         upstream.pop();
        if (fish > A[i]) {
          upstream.push(fish);
          break;
        }
      }
    }
  }
  return A.size() - eaten;
}