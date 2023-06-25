int solution(vector<int> &A) {
  int output = 0;
  double avg = 0;
  double minAvg = (A[0] + A[1]) / 2;
  for (unsigned int i = 2; i < A.size(); i += 1) {
    avg = (A[i - 2] + A[i - 1] + A[i]) / 3.0;
    if (minAvg > avg) {
      minAvg = avg;
      output = i - 2;
    }
    avg = (A[i - 1] + A[i]) / 2.0;
    if (minAvg > avg) {
      minAvg = avg;
      output = i - 1;
    }
  }
  return output;
}