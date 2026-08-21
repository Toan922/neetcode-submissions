class Solution {
public:
    int search(vector<int>& nums, int target) {
        //init the left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        //keep iterating until left is past right
        while(left <= right)
        {
            //calculate the midpoint of the 2 pointers
            int mid = (right - left) / 2 + left;

            //check midpoint's val against the target
            if(nums[mid] == target) return mid;
            //otherwise if midpoint > target -> decrement right
            else if(nums[mid] > target) right--;
            //otherwise midpoint is < target -> increment left
            else left++;
        }

        //if search failed -> return -1
        return -1;
    }
};
