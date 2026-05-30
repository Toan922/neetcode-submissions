class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //iterate through each row from row 0 to row 8
        for(int r = 0; r < 9; r++)
        {
            //init a hash set for seen elements where it resets each new row
            unordered_set<int> seen;

            //iterate through each col in that row to check for if there are dupes
            for(int c = 0; c < 9; c++)
            {
                //if the elem is an empty space/. then skip this col
                if(board[r][c] == '.') continue;
                //if the elem has prev been seen in this row then return invalid board/false
                if(seen.count(board[r][c])) return false;
                //if the two above cases did not pass -> insert elem into seen
                seen.insert(board[r][c]);
            }
        }

        //iterate through each col from col 0 to col 8
        for(int c = 0; c < 9; c++)
        {
            //init a hash set for seen elements where it resets each new col
            unordered_set<int> seen;
            
            //iterate through each row in that col to check for if there are dupes
            for(int r = 0; r < 9; r++)
            {
                //if the elem is an empty space/. then skip this row
                if(board[r][c] == '.') continue;
                //if the elem has prev been seen in this col then return invalid board/false
                if(seen.count(board[r][c])) return false;
                //if the two above cases did not pass -> insert elem into seen
                seen.insert(board[r][c]);
            }
        }

        //iterate through each sqr from sqr 0 to sqr 8
        for(int s = 0; s < 9; s++)
        {
            //init a hash set for seen elements where it resets each new col
            unordered_set<int> seen;

            //iterate through each row and col in that sqr
            for(int r = 0; r < 3; r++)
            {
                for(int c = 0; c < 3; c++)
                {
                    //calc the row to be the grid / 3 * 3 + row (* 3 is to convert from grid calc to coord)
                    int row = (s / 3) * 3 + r;
                    //calc the col to be the grid % 3 * 3 + col
                    int col = (s % 3) * 3 + c;

                    //if the elem is an empty space -> continue past loop
                    if(board[row][col] == '.') continue;
                    //if the elem is in seen then return invalid board/false
                    if(seen.count(board[row][col])) return false;
                    //otherwise insert the board elem into seen
                    seen.insert(board[row][col]);
                }
            }
        }

        //if all loops passed -> return valid board/true
        return true;
    }
};
