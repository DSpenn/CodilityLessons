#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> &A) {
    set<int> s;
    for (int x : A) { 
        s.insert(x);
    }
    int i = 1;
    while (s.count(i)) i++;
    return i;
}
