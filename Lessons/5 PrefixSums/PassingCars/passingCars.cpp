int solution(vector<int> &A) {
  int max = 1000000000;
  int lane = 0;
  int sum = 0;
  for (int a : A) {
    if (a == 0)
      lane += 1;
    else
      sum += lane;
    if (sum > max) return -1;
  }
  return sum;
}
