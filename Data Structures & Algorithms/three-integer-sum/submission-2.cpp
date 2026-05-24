#include <ranges>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (auto const [i, t] : views::enumerate(nums))
        {
            if ((i > 0) && (t == nums[i - 1])) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int threeSum = t + nums[left] + nums[right];

                if (threeSum > 0)
                {
                    right--;
                }
                else if (threeSum < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back({t, nums[left], nums[right]});
                    do
                    {
                        left++;
                    }
                    while((nums[left] == nums[left - 1]) && (left < right));
                }
            }
        }

        return result;
    }
};
