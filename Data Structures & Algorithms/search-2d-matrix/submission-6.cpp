class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //init the outer left and right ptrs
        int outerleft = 0;
        int outerright = matrix.size() - 1;

        //init the value that will hold the index of the potential target vector
        int potentialtarget;

        //continue looping until outer left has passed outer right
        while(outerleft <= outerright)
        {
            //calculate the midpoint vector to check
            int midvector = (outerright - outerleft) / 2 + outerleft;

            //reference the middle vector
            const vector<int>& checkvector = matrix[midvector];

            //check to see if target is in range of the midvector
            if(checkvector[0] <= target && target <= checkvector[checkvector.size() - 1])
            {
                potentialtarget = midvector;
                break;
            }
            //otherwise check if target is < middle vector's left bound -> outer right is too big
            else if(checkvector[0] > target) outerright = midvector - 1;
            //else outer left is too small
            else outerleft = midvector + 1;
        }

        //init the inner left and right ptrs used for binary search
        int innerleft = 0;
        int innerright = matrix[potentialtarget].size() - 1;

        //now check to see if target exists in the vector
        while(innerleft <= innerright)
        {
            int mid = (innerright - innerleft) / 2 + innerleft;

            //reference the current vector
            const vector<int>& inrangevector = matrix[potentialtarget];

            //check to see if the mid point of the vector == target
            if(inrangevector[mid] == target) return true;
            //otherwise check to see if it is < target -> inner right is too larget
            else if(inrangevector[mid] > target) innerright = mid - 1;
            //otherwise innerleft is too small
            else innerleft = mid + 1;
        }

        //return false since loop has completed without finding target
        return false;
    }
};
