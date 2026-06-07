class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //init a val to serve as the leftmost val in the binary search -> start w/ 1 since min bpm is 1
        int slowest = 1;
        //init a val to serve as the rightmost val in the binary search -> start w/ the biggest pile val
        int fastest = *max_element(piles.begin(), piles.end());
        //init the potential result to the rightmost val
        int res = fastest;

        //keep looping until left and right meet up
        while(slowest <= fastest)
        {
            //find the middle of the range between slowest and fastest possible k's
            int middle = (fastest - slowest) / 2 + slowest;
            //init a val keeping track of the hours spent eating using the middle k val
            long long hoursTaken = 0;

            //perform a check if the middle val is able to serve as the k val
            for(const int& pile : piles)
            {
                //add the ceiling of the pile / k onto hoursTaken
                hoursTaken += (pile + middle - 1) / middle;
            }

            //check if hoursTaken is less than h -> if so take the min between the curr middle and res
            if(hoursTaken <= h)
            {
                //update res
                res = min(middle, res);
                //update fastest to be one less than middle
                fastest = middle - 1;
            }
            //otherwise make slowest = middle + 1
            else slowest = middle + 1;
        }

        //return the val of the slowest possible k
        return res;
    }
};
