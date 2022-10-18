#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
  set<int> mySet;
  for(int i=0; i<A.size();i++) {
    if(mySet.count(A[i])==0)
      mySet.insert(A[i]);
    }
  int y = 1;
  while (mySet.count(y)) y +=1;
  return y;
  }
