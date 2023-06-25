#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> answer(P.size());
  vector<int> a(S.size() + 1);
  vector<int> c(S.size() + 1);
  vector<int> g(S.size() + 1);

  for (size_t i = 0; i < S.size(); i++) {
    a[i + 1] = a[i] + (S[i] == 'A');
    c[i + 1] = c[i] + (S[i] == 'C');
    g[i + 1] = g[i] + (S[i] == 'G');
  }

  for (size_t i = 0; i < P.size(); i++) {
    if (a[Q[i] + 1] - a[P[i]] > 0)
      answer[i] = 1;
    else if (c[Q[i] + 1] - c[P[i]] > 0)
      answer[i] = 2;
    else if (g[Q[i] + 1] - g[P[i]] > 0)
      answer[i] = 3;
    else
      answer[i] = 4;
  }

  return answer;
}


/* // too slow 
#include <algorithm>
#include <string>
#include <vector>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
  vector<int> scores(P.size());
  string c;

  for (size_t x = 0; x < P.size(); x += 1) {
    if (P[x] == Q[x]) {
      c = S[P[x]];
      if (c == "A") {
        scores[x] = 1;
      } else if (c == "C") {
        scores[x] = 2;
      } else if (c == "G") {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    } else {
      c = S.substr(P[x], Q[x] + 1 - P[x]);
      if (c.find("A") != string::npos && c.find("C") != string::npos &&
          c.find("G") != string::npos && c.find("T") != string::npos) {
        scores[x] = 1;
      } else if (c.find("A") != string::npos) {
        scores[x] = 1;
      } else if (c.find("C") != string::npos) {
        scores[x] = 2;
      } else if (c.find("G") != string::npos) {
        scores[x] = 3;
      } else {
        scores[x] = 4;
      }
    }
  }
  return scores;
}
 */