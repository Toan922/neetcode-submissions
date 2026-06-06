class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //init a heap that will keep track of the curr max elem & its index as the root
        priority_queue<pair<int, int>> maxHeap;
        //init the vector that will hold the result
        vector<int> res;

        //loop over nums
        for(int i = 0; i < nums.size(); i++)
        {
            //push the value at index i and i onto the heap
            maxHeap.push({nums[i], i});

            //if the top of the heap is out of the window range -> keep popping
            while(maxHeap.top().second <= i - k) maxHeap.pop();

            //check if the window has finished forming -> if so push the top of the heap onto res
            if(i >= k - 1) res.push_back(maxHeap.top().first);
        }

        //once nums is done looping thru -> return res
        return res;
    }
};
