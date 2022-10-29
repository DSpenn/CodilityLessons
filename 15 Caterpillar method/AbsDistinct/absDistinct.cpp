#include <set>
#include <stdlib.h> 
int solution(vector<int> &A) {
  set<int> mySet;
for (auto &a : A)
{
  cout << a;
  mySet.insert(abs(a));
}
return mySet

}
