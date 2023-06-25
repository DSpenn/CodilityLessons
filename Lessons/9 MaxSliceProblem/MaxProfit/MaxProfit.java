class Solution {
  public int solution(int[] A) {
    int maxProfit = 0;
    int minPrice = Integer.MAX_VALUE;
  
    //for (int i = 0; i < A.length; i += 1) {
    for (int price : A) {
      minPrice = Math.min(minPrice, price);
      maxProfit = Math.max(maxProfit, (price - minPrice));
    }
    return maxProfit;
  }
}
