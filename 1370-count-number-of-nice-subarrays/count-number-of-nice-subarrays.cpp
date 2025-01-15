class Solution {
public:
    //same as Binary Subarrays With Sum
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }

    /* Helper function to find the number of 
    subarrays with sum less than or equal to k*/
    int helper(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0, r = 0;
        int sum = 0;
        int count = 0;

        while(r < nums.size()){
            sum = sum + nums[r] % 2;

            while(sum > k){
                sum = sum - nums[l] % 2;
                l++;
            }

            count += r - l + 1;
            r++;
        }

        return count;
    }
};