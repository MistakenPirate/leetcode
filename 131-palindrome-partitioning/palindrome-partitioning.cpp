class Solution {
public:
    vector<vector<string> > partition(string s) {
        //result to store all partitions
        vector<vector<string>> res;
        //temp vector to store current partition
        vector<string> path;
        //start dfs from index 0
        dfs( 0, s, path, res);
        return res;
    }

    void dfs(int index, string s, vector<string> &path, vector<vector<string>> &res){
        //if index reaches the end of string
        if(index == s.size()){
            //add the current partition to the result
            res.push_back(path);
            return;
        }

        //iterate over the substring starting from index
        for(int i = index; i < s.size(); i++){
            //check if substr is palindrome
            if(isPalindrome(s, index, i)){
                //if true, add it to currrent path
                path.push_back(s.substr(index, i - index + 1));
                //recur to the remaining substr
                dfs(i + 1, s, path, res);
                //backtrack: remove the last added substr
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};