class Solution {
    int numSubarraysWithSumLessEqualToGoal(vector<int>& nums, int goal){
        //if goal is -ve, there
        //can't be any valid subarray sum
        if(goal < 0) return 0;

        //pointer to maintain the current window
        int l = 0, r = 0;

        //variable to track the current 
        //sum of elements in the window
        int sum = 0;
        int count = 0;

        while(r < nums.size()){
            sum += nums[r];

            //shrink window from left
            //if the sum exceeds goal
            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLessEqualToGoal(nums, goal) 
               - numSubarraysWithSumLessEqualToGoal(nums, goal - 1);
    }
};