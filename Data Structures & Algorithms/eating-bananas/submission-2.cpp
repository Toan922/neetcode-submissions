class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //init something to track the the slowest k possible and the fastest k possible
        int slowest = 1;
        int fastest = *max_element(piles.begin(), piles.end());

        //set the banana eating speed k to be fastest
        int k = fastest;

        //keep looping while the slowest <= fastest to check every possible k in the range;
        while(slowest <= fastest)
        {
            //calculate the middle k in the range
            int middleK = (fastest - slowest) / 2 + slowest;

            //init a tracker that will tally up how many hours the middleK val will take
            long long hoursTaken = 0;

            //iterate over the piles and take the ceiling of pile / current k and add to hoursTaken
            for(const int& pile : piles)
            {
                //add the ceiling
                hoursTaken += (pile + middleK - 1) / middleK;
            }

            //check if hoursTaken is < h -> if so then update fastest to be smaller
            if(hoursTaken <= h)
            {
                fastest = middleK - 1;
                
                //also update k to be middleK
                k = middleK;
            }
            //otherwise the middleK would take too long so need to increase slowest
            else slowest = middleK + 1;
        }

        //return k at the end
        return k;
    }
};
