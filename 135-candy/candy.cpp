class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0)  return 0;

        vector<int> right(n, 1);
        vector<int> left(n, 1);

        
        for(int i = 1; i < n; i++){
            //if the current child's rating is
            //higher than the previous one
            if(ratings[i] > ratings[i - 1]){
                //give the current child one
                //more candy than the prev one
                left[i] = left[i - 1] + 1;
            }
        }    

        for(int i = n - 2; i >= 0; i--){
            //if the current child's rating is
            //higher than the next one
            if(ratings[i] > ratings[i +  1]){
                //give the current child one
                //more candy than the next one
                right[i] = right[i + 1] + 1;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            //each child gets the max
            //candies from right and left
            ans += max(right[i],left[i]);
        }

        return ans;
    }
};