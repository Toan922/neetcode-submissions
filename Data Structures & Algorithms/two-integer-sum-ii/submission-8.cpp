class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //if numbers is size 2 -> return 1 and 2
        if(numbers.size() == 2) return {1, 2};

        //init the left and right pointers
        int left = 0;
        int right = numbers.size() - 1;

        //keep iterating while left is < right
        while(left < right)
        {
            //reference the left and right ints
            int leftnum = numbers[left];
            int rightnum = numbers[right];

            //calc the sum of the curr lefts and rights
            int sum = leftnum + rightnum;

            //check sum against the target -> if > target -> decrement right
            if(sum > target) right--;
            //otherwise if < target -> increment left
            else if(sum < target) left++;
            //last option is sum == target -> return left and right
            else return {left + 1, right + 1};
        }

        return {};
    }
};
