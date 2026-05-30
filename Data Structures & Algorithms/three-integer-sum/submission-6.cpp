class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //init a 2D vector that will represent all triplets possible to be returned
        vector<vector<int>> res;

        //sort nums
        sort(nums.begin(), nums.end());

        //loop through nums
        for(int i = 0; i < nums.size(); i++)
        {
            //if the curr val is > 0 then break out of the loop
            if(nums[i] > 0) break;
            //if the curr index is > 0 and equals the same val as the prev index -> skip this iteration
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            //init a left and right pointer where left is curr index + 1 and right is the end of nums
            int left = i + 1;
            int right = nums.size() - 1;

            //do basic 2 ptr algo on sorted data
            while(left < right)
            {
                //init a three sum var that is calc based on the curr index + left index + right index
                int threeSum = nums[i] + nums[left] + nums[right];

                //perform check if sum is >, <, or = to 0
                //if the val is > 0 -> right is too large -> decr right
                if(threeSum > 0) right--;
                //if the val is < 0 -> left is too small -> incr left
                else if(threeSum < 0) left++;
                //otherwise add 3 vals to res then keep iterating left and right until new elems
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    
                    //iterate left and right 1 time
                    left++;
                    right--;

                    //keep iterating left until it sees a new number or is greater than right
                    while(left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
            }
        }

        //return the triplets
        return res;
    }
};
