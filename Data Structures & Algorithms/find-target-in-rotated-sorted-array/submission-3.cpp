class Solution {
public:
    int search(vector<int>& nums, int target) {
        //init the left and right ptrs to perf the binary search
        int left = 0;
        int right = nums.size() - 1;

        //keep looping while left <= right since every index in sorted range needs checking
        while(left <= right)
        {
            //calc the middle index
            int middle = (right - left) / 2 + left;

            //check if the middle element == target -> if so return middle
            if(nums[middle] == target) return middle;
            //check which side is sorted -> check if left segment is sorted
            else if(nums[left] <= nums[middle])
            {
                //this indicates that left half is sorted
                //check if the target lies in the range of left and middle -> update right
                if(nums[left] <= target && target < nums[middle]) right = middle - 1;
                //otherwise the target is in the right segment
                else left = middle + 1;
            }
            //otherwise right segment is sorted
            else
            {
                //check if the target lies in the range between middle and right -> update left
                if(nums[middle] < target && target <= nums[right]) left = middle + 1;
                //otherwise target is in left segment
                else right = middle - 1;
            }
        }

        //assume that if loop completed w/ no returning -> target DNE in nums -> return -1
        return -1;
    }
};
