class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //init the result vector that we will return at the end
        vector<vector<int>> result;

        //sort nums to make it easier to apply 2 ptr algo to
        sort(nums.begin(), nums.end());

        //loop through all of nums by index
        for(int i = 0; i < nums.size(); i++)
        {
            /*
                since looping in ascending order and only looking at future indices ->
                if the curr index is > 0 -> break out of the loop since all possible
                combos has been found
            */
            if(nums[i] > 0) break;
            /*
                also if the curr index > 0 and == val of prev index -> skip iteration since 
                this combo has been accounted for in the prev iteration
            */
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            //now begin the left ptr as index i + 1 and right ptr as the end of nums
            int left = i + 1;
            int right = nums.size() - 1;

            //keep looping while left < right since looking for pairs
            while(left < right)
            {
                //begin by calculating the sum of curr index + left + right
                int threesum = nums[i] + nums[left] + nums[right];

                //check to see if threesum == 0
                if(threesum == 0)
                {
                    //add values to res
                    result.push_back({nums[i], nums[left], nums[right]});

                    //iterate both left and right
                    left++;
                    right--;

                    //keep iterating left while left < right and until new left is found
                    while(left < right && nums[left] == nums[left - 1]) left++;
                }
                //else check to see if threesum > 0 -> indicator that right is too big
                else if(threesum > 0) right--;
                //otherwise left is too small
                else left++;
            }
        }

        //at the end return result
        return result;
    }
};
