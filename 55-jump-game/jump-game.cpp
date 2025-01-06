class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        //how i can proceed in this problem is by using a maxIndex
        //i'll traverse the array and if the index is greater
        //than maxIndex that jumpGame allows, i'll return false
        //otherwise i'll update maxIndex as the maximum possible
        //index the game allows (maxIndex = max(maxIndex, i + nums[i]))
        //if all goes right, at the end i return true;
        for(int i = 0; i < n; i++){
            if(i > maxIndex)
                return false;
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};