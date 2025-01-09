class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0, n = nums.size();

        for(int i = 0; i < n; i++)
            XOR = XOR ^ nums[i];

        return XOR;

        // int n = nums.size();
        // unordered_map<int,int> mpp;

        // for(int i = 0; i < n; i++)
        //     mpp[nums[i]]++;

        // for(auto it: mpp)
        //     if(it.second == 1)
        //         return it.first;
    
        // return -1;
    }
};