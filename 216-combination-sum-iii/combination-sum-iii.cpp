class Solution {
    void func(int sum, int last, vector<int> &nums, int k, vector<vector<int>> &ans){
      //if the sum is zero and the number of elements is k
      if(sum == 0 && nums.size() == k){
        //add the current combination to the ans
        ans.push_back(nums);
        return;
      }
      //if the sum is less than or equal to zero or the number
      //of elements exceed k
      if(sum <= 0 || nums.size() > k) return;

      //iterate from the last number to 9
      for(int i = last; i <= 9; i++){
        //if the current number is less than or equal to the sum
        if(i <= sum){
          //add the number to the current combination
          nums.push_back(i);
          //recursive call with updated sum and next number
          func(sum - i, i + 1, nums, k, ans);
          //remove the last number to backtrack
          nums.pop_back();
        } else {
          //if the number is greater than the sum, break the loop
          break;
        }
      }

    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	  vector<vector<int>> ans; 
        vector<int> nums; 
        // Call the recursive function with initial parameters
        func(n, 1, nums, k, ans);
        return ans; 
    }
};