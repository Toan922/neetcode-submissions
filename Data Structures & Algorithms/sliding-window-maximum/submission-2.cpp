class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //using a double ended queue to keep track of curr max's index
        deque<int> winMax;
        //init a int vector that will be returned at the end
        vector<int> res;

        //loop over nums via index
        for(int i = 0; i < nums.size(); i++)
        {
            //while the deque is not empty and its front elem is out of window -> keep popping front
            while(!winMax.empty() && winMax.front() == i - k)
            {
                winMax.pop_front();
            }

            //while the deque is not empty and there are elems < curr elem -> keep popping back
            while(!winMax.empty() && nums[winMax.back()] <= nums[i])
            {
                winMax.pop_back();
            }

            //push i onto winMax
            winMax.push_back(i);

            //if window is formed -> take the front elem push onto res
            if(i >= k - 1) res.push_back(nums[winMax.front()]);
        }

        //return that int vector
        return res;
    }
};
