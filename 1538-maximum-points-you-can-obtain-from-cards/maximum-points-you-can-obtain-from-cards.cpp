class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        int lsum = 0, rsum = 0, maxSum = 0;

        //calculate the initial sum of first k cards
        for(int i = 0; i < k; i++){
            lsum += cardScore[i];
            maxSum = lsum;
        }

        //init rightIndex to iterate array from last
        int rightIndex = cardScore.size() - 1;

        for(int i = k - 1; i >= 0; i--){
            //remove the score of the ith card from leftsum
            lsum -= cardScore[i];
            //add the score of the card from
            //the right to the right sum
            rsum += cardScore[rightIndex--];

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};