class Solution {
public:
    int search(vector<int>& nums, int target) {
        //start the left and right ptrs where left = start and right = end
        int left = 0;
        int right = nums.size() - 1;

        //keep looping while left is <= right -> checks every possible index in worst case this way
        while(left <= right)
        {
            //calculate the middle index to be right - left / 2 + left -> prevents overflow this way
            int middle = (right - left) / 2 + left;

            //check if the middle elem == target -> if so return middle
            if(nums[middle] == target) return middle;

            //otherwise check if the target is < or > middle and update left/right accordingly
            if(target < nums[middle])
            {
                //represents the scenario where the middle is > target -> update right to be smaller
                right = middle - 1;
            }
            //otherwise target is > middle -> need to make left bigger
            else left = middle + 1;
        }

        //if the loop has concluded w/ out returning an index -> means the target DNE in nums -> return -1
        return -1;
    }
};
