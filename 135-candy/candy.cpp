class Solution {
public:
    int candy(vector<int>& ratings) {
        //get number of children
        int n = ratings.size();
        if(n == 0)  return 0;

        int i = 1;
        int sum = 1;

        while(i < n){
            if(ratings[i] == ratings[i - 1]){
                sum++;
                i++;
                continue;
            }

            //init the candy count
            //for increasing rating trend
            int peak = 1;

            //loop through increasing ratings trend
            while(i < n && ratings[i] > ratings[i - 1]){
                peak++;
                sum += peak;
                i++;
            }

            //init the candy count
            //for decreasing rating trend
            int down = 1;
            
            //loop through the decreasing ratings trend
            while(i < n && ratings[i] < ratings[i - 1]){
                sum += down;
                i++;
                down++;
            }

            //check if candy count for
            //decreasing trend exceeds the peak
            if(down > peak){
                //adjust the total number of
                //candies to satisfy the condition
                sum += (down - peak);
            }
        }

        //total candies returned
        return sum;
    }
    
    // int candy(vector<int>& ratings) {
    //     int n = ratings.size();
    //     if(n == 0)  return 0;

    //     vector<int> right(n, 1);
    //     vector<int> left(n, 1);

        
    //     for(int i = 1; i < n; i++){
    //         //if the current child's rating is
    //         //higher than the previous one
    //         if(ratings[i] > ratings[i - 1]){
    //             //give the current child one
    //             //more candy than the prev one
    //             left[i] = left[i - 1] + 1;
    //         }
    //     }    

    //     for(int i = n - 2; i >= 0; i--){
    //         //if the current child's rating is
    //         //higher than the next one
    //         if(ratings[i] > ratings[i +  1]){
    //             //give the current child one
    //             //more candy than the next one
    //             right[i] = right[i + 1] + 1;
    //         }
    //     }

    //     int ans = 0;
    //     for(int i = 0; i < n; i++){
    //         //each child gets the max
    //         //candies from right and left
    //         ans += max(right[i],left[i]);
    //     }

    //     return ans;
    // }
};