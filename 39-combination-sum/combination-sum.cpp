class Solution {
  //revursive func to find all the subsequences with the given target sum
  void func(vector<int>& v, int i, int sum, vector<int>& v2, vector<vector<int>>& ans){
    //base case : if the sum is zero
    //add the current subsequence to the res
    if(sum == 0){
      ans.push_back(v2);
      return;
    }

    //base case : if the sum becomes negative
    if(sum < 0)
      return;

    //base case : if no elements are left
    if(i < 0)
      return;

    //exclude the current element and move to the next
    func(v, i - 1, sum, v2, ans);

    //include the current element in the subsequence
    v2.push_back(v[i]);

    //recursively call the function with the included element
    func(v, i, sum - v[i], v2, ans);

    //backtrack by removing the last added element
    v2.pop_back();
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        
        // Start the recursive process
        func(candidates, candidates.size() - 1, target, v, ans);
        
        return ans;
    }
};