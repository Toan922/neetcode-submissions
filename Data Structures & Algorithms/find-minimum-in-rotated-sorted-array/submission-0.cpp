class Solution {
public:
    int findMin(vector<int> &nums) {
        //init the left and right to perf binary search
        int left = 0;
        int right = nums.size() - 1;

        //keep looping while left is <= right
        while(left < right)
        {
            //calculate the middle as R - L / 2 + L to prevent overflow
            int mid = (right - left) / 2 + left;

            //check if which 2 indices are within the same segment
            if(nums[mid] > nums[right])
            {
                //if left < mid -> min is in the right half -> discard left half
                left = mid + 1;
            }
            else right = mid;
        }

        return nums[left];
    }
};
