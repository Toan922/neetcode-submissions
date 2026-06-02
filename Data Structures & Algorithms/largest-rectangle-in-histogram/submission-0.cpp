class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //have the case where heights.size() == 1 since area is 1 x first col height
        if(heights.size() == 1) return heights[0];

        //init an int var that keeps track of max area found thus far
        int maxArea = 0;
        //init a stack keeping track of the index of the largest bar found so far
        stack<int> currLargest;

        //loop through all the indices of heights
        for(int i = 0; i <= heights.size(); i++)
        {
            //handle the case where size is only increasing by setting a virtual 0 height bar at the end of heights
            int currHeight = (i == heights.size()) ? 0 : heights[i];

            //while the curr elem is < top elem of stack -> keep calc area and popping
            while(!currLargest.empty() && currHeight < heights[currLargest.top()])
            {
                //get the index of the highest bar seen thus far then pop it off
                int height = heights[currLargest.top()];
                currLargest.pop();

                //init a var to store the width
                int width = 0;

                //depending on whether the stack is empty or not calc the area w/ 2 diff vals of left
                if(currLargest.empty()) width = i;
                else width = i - currLargest.top() - 1;

                //take the max area to be either largest area seen so far or the area just found
                maxArea = max(maxArea, height * width);
            }

            //afterwards push on the index
            currLargest.push(i);
        }

        //return max area seen
        return maxArea;
    }
};
