class Solution {
public:
    int maxArea(vector<int>& heights) {
        //init a var that represents the max area of water that can be stored
        int maxArea = 0;
        //init a left and right pointer where left = start and right = end of vector
        int left = 0;
        int right = heights.size() - 1;

        //keep looping until left > right
        while(left < right)
        {
            //init an int var representing the curr area of water being stored
            int currArea = (right - left) * min(heights[left], heights[right]);

            //check whether the left height is <= right height -> move left inwards
            if(heights[left] <= heights[right]) left++;
            //otherwise right height < left height -> move right inwards
            else right--;

            //take maxArea as the max between currArea and maxArea
            maxArea = max(maxArea, currArea);
        }

        //return maxArea
        return maxArea;
    }
};
