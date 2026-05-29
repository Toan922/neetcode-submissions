class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //init a prefix array going front to back that keeps track of products so far
        vector<int> frontBack(nums.size(), 1);
        //do the same for a suffix array going back to front;
        vector<int> backFront(nums.size(), 1);
        //init the int vector that will be returned
        vector<int> products(nums.size());

        //loop through each index of nums starting w/ the second index
        for(int i = 1; i < nums.size(); i++)
        {
            //insert the product of the prev index of frontBack and the prev num
            frontBack[i] = frontBack[i - 1] * nums[i - 1];
        }
        //loop through each index of nums starting w/ the second to last index
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            //insert the product of the next index of backFront and the next num
            backFront[i] = backFront[i + 1] * nums[i + 1];
        }
        //loop through each index of nums again this time using that index to calculate its product
        for(int i = 0; i < nums.size(); i++)
        {
            //insert the product as the product of the prefix and suffix indices
            products[i] = frontBack[i] * backFront[i];
        }

        //return products
        return products;
    }
};
