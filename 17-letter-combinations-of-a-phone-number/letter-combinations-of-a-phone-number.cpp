class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        //mapping digits to corresponding characters
        string combos[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans; //vector to store result
        string s = ""; //temp string to build combinations
        //initiate rec func
        func(0, digits, s, ans, combos);
        return ans;//return the res
    }

    void func(int ind, string digits, string s, vector<string> &ans, string combos[]){
        //base case: if index reaches the end of digits
        if(ind == digits.size()){
            //add the current combination to the answer
            ans.push_back(s);
            return;
        }
        //convert the current char to an integer
        int digit = digits[ind] - '0';
        //loop through the corr chars
        for(int i = 0; i < combos[digit].size(); i++){
            //recursively call function with next index
            //add current char to the string
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
        }
    }
};