#include <stack>
int solution(string &S) {
  if (S.size() == 0) return 1;  // if input empty
  if (S.size() % 2) return 0;   // if odd input cant be properly nested

  stack<char> stk;

  for (auto &s : S)
    if (s == '(' or s == '[' or s == '{')
      stk.push(s);
    else if (stk.size() == 0)
      return false;
    else if (s == ')' and stk.top() != '(')
      return false;
    else if (s == ']' and stk.top() != '[')
      return false;
    else if (s == '}' and stk.top() != '{')
      return false;
    else
      stk.pop();

  return stk.size() == 0;
}
