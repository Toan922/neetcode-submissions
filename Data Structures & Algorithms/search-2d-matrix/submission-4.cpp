class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //init the top and bottom ptrs that will keep track of which vector contains the range of the target
        int top = 0;
        int bottom = matrix.size() - 1;

        //init the value that will hold the correct row for future binary searching
        int row = 0;

        //keep looping while top <= bottom to perform the binary search
        while(top <= bottom)
        {
            //calc the middle vector to be bottom - top / 2 + top to prevent overflow
            int middle = (bottom - top) / 2 + top;

            //name the middle matrix for easy referencing
            const vector<int>& middleMatrix = matrix[middle];

            //check if the middle vector contains the range that may contain target -> break loop
            if(*middleMatrix.begin() <= target && target <= *middleMatrix.rbegin())
            {
                //set row to be = middle then break from the loop
                row = middle;
                break;
            }
            //if the target is below the middle's range -> bring the bottom inward
            else if(target < *middleMatrix.begin()) bottom = middle - 1;
            //otherwise the target is above the middle's range -> bring the top inward
            else top = middle + 1;
        }

        //name the selected vector for easy referencing
        const vector<int>& targetVector = matrix[row];

        //init the left and right ptrs that will keep track of the elems in the vector
        int left = 0;
        int right = targetVector.size() - 1;

        //keep looping while left <= right to perform binary search of a target
        while(left <= right)
        {
            //calculate the middle index similarly to earlier
            int middle = (right - left) / 2 + left;

            //check if the middle index == target -> if so return true
            if(targetVector[middle] == target) return true;
            //if the middle element is > target -> make the right smaller to look at a lower number
            else if(target < targetVector[middle]) right = middle - 1;
            //otherwise middle element is < target -> need to make left bigger to look at larger number
            else left = middle + 1;
        }

        //if both loops concluded can assume that the target DNE in the matrix -> return false
        return false;
    }
};
