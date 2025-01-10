class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //optimal
        int n = nums.size();
        long XOR = 0;

        for(int i = 0; i < n; i++)
            XOR = XOR ^ nums[i];
        
        //getting the rightmost set bit
        int rightmost = (XOR & (XOR - 1)) ^ XOR;

        int XOR1 = 0, XOR2 = 0;

        for(int i = 0; i < n; i++){
            //divide numbers into buckets
            //based on rightmost set bit
            if(nums[i] & rightmost)
                XOR1 = XOR1 ^ nums[i];
            else 
                XOR2 = XOR2 ^ nums[i];
        }

        return {XOR1, XOR2};


        //brute
        // unordered_map<int,int> mpp;
        // vector<int> res;
        // int n = nums.size();

        // for(int i = 0; i < n; i++)
        //     mpp[nums[i]]++;

        // for(auto it: mpp){
        //     if(it.second == 1)
        //         res.push_back(it.first);
        // }

        // return res;
    }
};