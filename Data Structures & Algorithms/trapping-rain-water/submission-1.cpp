class Solution {
public:
    int trap(vector<int>& height) {
        //init a res val that will represent max area of water that can be held
        int res = 0;
        //init a left and right pointer w/ left = start and right = end
        int left = 0;
        int right = height.size() - 1;
        //init a tracker var that keeps track of the tallest wall seen at the left and right points
        int leftHigh = height[left];
        int rightHigh = height[right];

        //keep looping until left crosses right
        while(left < right)
        {
            //dependent on whether the left wall is the smaller wall -> move either left or right inwards
            if(leftHigh < rightHigh)
            {
                left++;
                leftHigh = max(leftHigh, height[left]);
                res += leftHigh - height[left];
            }
            //otherwise right is smaller -> move right inwards, update rightHigh, and then add to res
            else
            {
                right--;
                rightHigh = max(rightHigh, height[right]);
                res += rightHigh - height[right];
            }
        }

        //return res
        return res;
    }
};
