class Solution {
public:
    int findMin(vector<int> &nums) {
        //set a left and right pointer to perf the binary search
        int left = 0;
        int right = nums.size() - 1;

        //keep looping while left is < right since aim is to squeeze until left lands on the min
        while(left < right)
        {
            //calculate the middle index
            int middle = (right - left) / 2 + left;

            //perform the check to see which side is sorted
            if(nums[middle] > nums[right])
            {
                //if the middle index > right index then the min is somewhere on the right segment
                left = middle + 1;
            }
            //otherwise the min element is on the left segment -> set right to middle
            else right = middle;
        }

        //at the end left should be the min element -> return left
        return nums[left];
    }
};
