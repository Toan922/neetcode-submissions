class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), 1);

        //perform the forward pass of nums calculating products as if it were the prefix vector
        for(int i = 1; i < nums.size(); i++)
        {
            products[i] = products[i - 1] * nums[i - 1];
        }
        //init a running suffix product tracker
        int suffix = 1;
        //perform the backwards pass of nums calculating products as if it were the suffix vector
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            //since products == prefix, multiply the sitting element in i by suffix
            products[i] *= suffix;
            //increment suffix by its product w/ the val in index i in nums to keep track of suffix
            suffix *= nums[i];
        }

        //return products since it now has both the prefix * suffix for each index
        return products;
    }
};
