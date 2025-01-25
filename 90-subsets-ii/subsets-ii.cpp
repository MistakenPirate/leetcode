class Solution {
  void func(int ind, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans){
    //base case: if index reaches the end of nums
    if(ind == nums.size()){
      //add the current subset to the res
      ans.push_back(arr);
      return;
    }
    //include the current element in the subset
    arr.push_back(nums[ind]);
    //recur for the next index
    func(ind + 1, arr, nums, ans);
    //backtrack: remove the current element from the subset
    arr.pop_back();

    // Skip duplicates and recur for the next unique element
    for(int j = ind + 1; j < nums.size(); j++){
      if(nums[j] != nums[ind]){
        func(j, arr, nums, ans);
        return;
      }
    }

    //ensure the function finishes when no more unique elements are left
    func(nums.size(), arr, nums, ans);

  }
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
      vector<vector<int>> ans;  //list of subsets
      vector<int> arr;          //current subset
      sort(nums.begin(), nums.end()); //sort the array to handle dupes
      func(0, arr, nums, ans); //start rec
      return ans;
    }
};