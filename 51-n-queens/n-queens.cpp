class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        //list to store the solutions
        vector<vector<string>> ans;
        //init the board with empty cells
        vector<string> board(n, string(n, '.'));

        //start placing queens from the first column
        func(0, ans, board);
        return ans;
    }
    //function to place queens on the board
    void func(int col, vector<vector<string>>& ans, vector<string> &board){
        //if all the columns are filled, add the soln to the ans
        if(col == board.size()){
            ans.push_back(board);
            return;
        }

        //try placing a queen in each row for the current column
        for(int row = 0; row < board.size(); row++){
            //check if it's safe to place a queen
            if(safe(board, row, col)){
                //place the queen
                board[row][col] = 'Q';
                //recursively place the queens in the next columns
                func(col + 1, ans, board);
                //remove the queen and backtrack
                board[row][col] = '.';
            }
        }
    }
    //check if it's safe to place a queen at board[row][col]
    bool safe(vector<string>& board, int row, int col){
        int r = row, c = col;

        //check upper left diagonal
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        //reset to original pos
        r = row;
        c = col;

        //check the left side
        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;
        }

        //reset to the orignal postition
        r = row;
        c = col;

        //check lower left diagonal
        while(r < board.size() && c >= 0){
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }

        //if no queen is found, it's safe
        return true;
    }
};