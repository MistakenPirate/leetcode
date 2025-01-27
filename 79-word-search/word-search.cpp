class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        //iterate through each cell in the board
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                //if the first char matches, start the search
                if(board[i][j] == word[0]){
                    //if the word is found, return true
                    if(func(board, i, j, word, 0))
                        return true;
                }
            }
        }
        //if the word is not found, return false
        return false;
    }
    bool func(vector<vector<char>> &v, int i, int j, string& s, int k){
        //if all chars of the word are found
        if(k == s.size()){
            return true;
        }
        //boundary condition and char mismatch check
        if(i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || s[k] != v[i][j]){
            return false;
        }

        //init ans as false
        bool ans = false;

        //temporarily mark the cell as visited
        char x = v[i][j];
        v[i][j] = ' ';

        //check all four possible directions
        ans |= func(v, i + 1, j, s, k + 1);
        ans |= func(v, i - 1, j, s, k + 1);
        ans |= func(v, i, j + 1, s, k + 1);
        ans |= func(v, i, j - 1, s, k + 1);

        //restore the original char in the cell
        v[i][j] = x;
        return ans;
    }
};