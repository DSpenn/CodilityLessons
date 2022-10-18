#include <iostream>
#include <set>
using namespace std;

int solution(int X, vector<int> &A) {
    set<int> s;
    int y = 0;
    for (int n : A) {
        s.insert(n);
        if (s.size() == X) {
          return y; 
      }
    y++;
    }
    return -1;
}