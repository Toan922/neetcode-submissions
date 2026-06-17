class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //set smallerVector to be a reference to the shortest vector betweeen nums1 and nums2
        const vector<int>& smallerVector = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        //vice versa for biggerVector
        const vector<int>& biggerVector = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        //init the left and right ptrs of the binarySearch vector to be the beginning and end of binarySearch
        int left = 0;
        int right = smallerVector.size();

        //init the median that we will be returning at the end
        double median = 0;

        //calculate the total length of the 2 vectors then check to see if it is odd or even
        int totalLength = nums1.size() + nums2.size();

        //continue looping while left <= right
        while(left <= right)
        {
            //calculate the middle index of the smallerVector and middle of the biggerVector based on this middle
            int middleSmall = (right - left) / 2 + left;
            //calculate the middle of the other vector based on this middle
            int middleBig = (totalLength + 1) / 2 - middleSmall;

            //save the middle and middle - 1 values of each vector for comparison
            int leftSmall = (middleSmall > 0) ? smallerVector[middleSmall - 1] : INT_MIN;
            int rightSmall = (middleSmall < smallerVector.size()) ? smallerVector[middleSmall] : INT_MAX;

            int leftBig = (middleBig > 0) ? biggerVector[middleBig - 1] : INT_MIN;
            int rightBig = (middleBig < biggerVector.size()) ? biggerVector[middleBig] : INT_MAX;

            //compare to see if the calculated middles correctly partition the 2 arrays
            if(leftSmall <= rightBig && leftBig <= rightSmall)
            {
                //in this scenario -> partition is correct therefore update the median accordingly and break
                //in the scenario that the length is even -> get the average between largest lefts and smallest middles
                if(totalLength % 2 == 0)
                {
                    median = (max(leftSmall, leftBig) + min(rightSmall, rightBig)) / 2.0;
                }
                //if the total length is odd then median sits in the left partition as the largest element
                else median = max(leftSmall, leftBig);
                //once median is stored -> break out of the loop since median has been found
                break;
            }
            //otherwise check to see whether the left or right of binarySearch needs to be brought inwards
            else if(leftSmall > rightBig)
            {
                //the right side of binarySearch is too large so needs to be brought in
                right = middleSmall - 1;
            }
            //last option is that left of binarySearch is too small so needs to be brought up;
            else left = middleSmall + 1;
        }

        //return the median
        return median;
    }
};
