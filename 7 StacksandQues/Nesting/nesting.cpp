int solution(string &S) {
  int count = 0;
  for (int i = 0; i < S.size(); i++) {
    //cout << S.at(i);
    if (S.at(i) == '(')
      count++;
    else if (S.at(i) == ')')
      count--;
    if (count < 0) return 0;
  }
  return count == 0 ? 1 : 0;
}
