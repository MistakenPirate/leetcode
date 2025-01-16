class Solution {
public:
    int minSwaps (string s) {
        int n = s.length();

        //if string is of odd length, 
        //it is not possible to balance
        //the parenthesis
        if(n % 2) return -1;

        //to store the count of opening and closing bracket
        int open = 0, close = 0;

        for(int i = 0; i < n; i++){
            //increment open count if opening bracket is found
            if(s[i] == '[') open++;
            //else closing bracket is found
            else{
                //if a opening bracket is there
                //a pair of balanced parenthesis is formed
                if(open > 0) open--;

                //otherwise the closing bracket remain unbalanced
                else close++;
            }
        }

        int ans = (max(open, close) + 1) / 2;
        return ans;
    }
};
