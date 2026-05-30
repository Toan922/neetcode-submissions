class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //init a left and right index where left = start of numbers and right = end
        int left = 0;
        int right = numbers.size() - 1;

        //keep iterating while left < right since same element cannot be used
        while(left < right)
        {
            //calc the sum of the left and right elem
            int sum = numbers[left] + numbers[right];

            //if the sum == target then exit the loop
            if(sum == target) break;
            //check if the sum > target -> indicates that right elem is too large -> decr right
            if(sum > target) right--;
            //otherwise the sum < target -> left elem is too small -> incr left
            else left++;
        }

        //return the left index and right index + 1 due to answer being 1-indexed
        return {left + 1, right + 1};
    }
};
