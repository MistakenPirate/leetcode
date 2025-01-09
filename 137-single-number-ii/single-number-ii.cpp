class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        int n = nums.size();
        int ans = 0;

        for(int bitIndex = 0; bitIndex < 32; bitIndex++){
            int count = 0;
            for(int i = 0; i < n; i++)
                //if the ith bit is set, increase count
                if(nums[i] & (1 << bitIndex))
                    count++;
            
            if(count % 3 == 1)
                //set the ith bit of ans
                ans = ans | (1 << bitIndex);
        }

        return ans;


        //brute
        
        // unordered_map<int,int> mpp;
        // int n = nums.size();

        // for(int i = 0; i < n; i++)
        //     mpp[nums[i]]++;
        
        // for(auto it: mpp)
        //     if(it.second == 1)
        //         return it.first;

        // return -1;
    }
};