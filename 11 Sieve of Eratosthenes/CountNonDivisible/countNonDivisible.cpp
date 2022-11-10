#include <vector>

vector<int> solution(vector<int> &A) {
  vector<int> counters(A.size() * 2 + 1);
  for (size_t x = 0; x < A.size(); x += 1) {
    counters[A[x]]++;
  }
  // for (int x : counters) { cout << x << " "; }
  vector<int> a(A.size());
  int nonDivisor = A.size();
  int num = 0;
  for (size_t x = 0; x < A.size(); x++) {
    num = A[x];
    nonDivisor = A.size();
    for (size_t i = 1; i * i <= num; i += 1) {
      if (num % i != 0) { continue; }
      nonDivisor -= counters[i];
      if (i * i != num) {
        nonDivisor -= counters[num / i];
      }
      a[x] = nonDivisor;
    }
  }
  return a;
}


//large_extreme large, all the same values, length = 50,000✘TIMEOUT ERROR running time: 0.184 sec., time limit: 0.100 sec. */
/* 
#include <vector>

vector<int> solution(vector<int> &A) {
  vector<int> counters(A.size() * 2 + 1);
  for (size_t x = 0; x < A.size(); x += 1) {
    counters[A[x]]++;
  }
  // for (int x : counters) { cout << x << " "; }
  vector<int> a(A.size());
  int nonDivisor = A.size();
  for (size_t x = 0; x < A.size(); x++) {
    nonDivisor = A.size();
    for (size_t i = 1; i * i <= A[x]; i += 1) {
      if (A[x] % i != 0) { continue; }
      nonDivisor -= counters[i];
      if (i * i != A[x]) {
        nonDivisor -= counters[A[x] / i];
      }
      a[x] = nonDivisor;
    }
  }
  return a;
}