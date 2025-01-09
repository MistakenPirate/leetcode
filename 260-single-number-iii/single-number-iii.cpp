class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> res;
        int n = nums.size();

        for(int i = 0; i < n; i++)
            mpp[nums[i]]++;

        for(auto it: mpp){
            if(it.second == 1)
                res.push_back(it.first);
        }

        return res;
    }
};