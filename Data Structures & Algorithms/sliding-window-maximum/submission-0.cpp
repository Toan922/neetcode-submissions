class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //init the final vector that we will be returning
        vector<int> res;

        //init the left and right indices that will determine the window size
        int left = 0;
        int right = k - 1;

        //keep iterating while right is less than the end of nums
        while(right < nums.size())
        {
            //find the index of the max number within the range of the left and right index
            auto maxWin = max_element(nums.begin() + left, nums.begin() + right + 1);

            //push that value onto the res vector
            res.push_back(*maxWin);

            //at the end iterate left and right
            left++;
            right++;
        }

        //return res
        return res;
    }
};
