class Solution {
public:
    int search(vector<int>& nums, int target) {
        //init the left and right ptrs to perf binary search
        int left = 0;
        int right = nums.size() - 1;

        //keep looping while left is less than/equal to right
        while(left <= right)
        {
            //calculate the middle index
            int middle = (right - left) / 2 + left;

            //check if the middle element is the target -> if true return middle
            if(nums[middle] == target) return middle;
            //otherwise check if the middle is > right -> left side is sorted
            else if(nums[left] <= nums[middle])
            {
                //check if the target is within the sorted side
                if(nums[left] <= target && target < nums[middle]) right = middle - 1;
                else left = middle + 1;
            }
            //otherwise right side is sorted
            else
            {
                //check if the target is within the sorted side
                if(nums[middle] < target && target <= nums[right]) left = middle + 1;
                else right = middle - 1;
            }
        }

        //assume that if loop has completed then target is not in nums -> return -1
        return -1;
    }
};
