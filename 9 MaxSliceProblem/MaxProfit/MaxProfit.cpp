#include <limits.h>
int solution(vector<int> &A) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for (int price : A) {
      minPrice = std::min(minPrice, price);
      maxProfit = std::max(maxProfit, (price - minPrice));
    }
    return maxProfit;
}
