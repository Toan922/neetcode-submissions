class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //doing binary search so init a left and right index ptr where left = start and right = end
        int left = 0;
        int right = matrix.size() - 1;

        int targetRow = -1;

        //calculate the middle index to be right + left / 2
        int middle = (right + left) / 2;

        //iterate while left <= right, if left > right then element cannot exist in the range
        while(left <= right)
        {
            //if target is in the range of the current middle row -> set targetRow = middle then break
            if((matrix[middle].front() <= target) && (matrix[middle].back() >= target))
            {
                targetRow = middle;
                break;
            }
            //if the current vector's smallest element (its first one) > target then right is too big
            else if(matrix[middle].front() > target)
            {
                //make right smaller than middle by 1
                right = middle - 1;
            }
            //otherwise the current largest element (current vector's last element) is < target
            else
            {
                //make left larger than middle by 1
                left = middle + 1;
            }

            // recalculate middle based on new left and right
            middle = (right + left) / 2;
        }

        //if target row is still -1 -> return false
        if (targetRow == -1) return false;

        //create an easy to reference vector that represents the current vector
        vector<int> binSearch = matrix[targetRow];

        //now do binary search on middle vector
        left = 0;
        right = binSearch.size() - 1;
        
        //calculate the current vector's mid point via right + left / 2
        middle = (right + left) / 2;

        //keep performing binary search until the left is > right which indicates element DNE
        while(left <= right)
        {
            //if the middle element == target -> return true
            if(binSearch[middle] == target)
            {
                return true;
            }
            //if middle element is > target then right is too big
            else if(binSearch[middle] > target)
            {
                //make right whatever the current middle is - 1
                right = middle - 1;
            }
            //otherwise the middle element is < target then left is too small
            else
            {
                //make left whatever the current middle is + 1
                left = middle + 1;
            }

            //update the inside middle
            middle = (right + left) / 2;
        }

        return false;
    }   
};
