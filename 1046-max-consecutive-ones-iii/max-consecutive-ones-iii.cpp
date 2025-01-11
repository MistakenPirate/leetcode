class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //better
        
        int n = nums.size();
        int maxLen = 0, zeros = 0;
        int l = 0, r = 0;

        while(r < n){
            if(nums[r] == 0) zeros++;
            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            r++;
        }

        return maxLen;

        //brute

        // int n = nums.size();
        // int maxLen  = 0;

        // for(int i = 0; i < n; i++){

        //     int zeros = 0;

        //     for(int j = i; j < n; j++){
            
        //         if(nums[j] == 0){
        //             zeros++;
        //         }
        //         if(zeros > k){
        //             break;
        //         }
                    
        //         maxLen = max(maxLen, j - i + 1);
                
        //     }
        // }

        // return maxLen;
    }
};