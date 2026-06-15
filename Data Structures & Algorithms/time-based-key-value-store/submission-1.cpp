class TimeMap {
//init the hash map that will store the key and its associated value/timestamp pairs
unordered_map<string, vector<pair<string, int>>> timeMap;

public:
    TimeMap() {
        //the constructor should remain empty as all the operations on timeMap are done through set and get
    }
    
    void set(string key, string value, int timestamp) {
        //set is simply placing the value and timestamp pair onto the associated key -> O(1) time since map
        //using push back here since we want to keep the vector in chronological order for later binary searching
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        //handle the case where key has not been used in get
        if(timeMap.find(key) == timeMap.end()) return "";

        //map the timeMap[key] to a variable to better reference it
        const vector<pair<string, int>>& keyValueTime = timeMap[key];

        //init the left and right pointers to perform the binary search where left = start and right = end
        int left = 0;
        int right = keyValueTime.size() - 1;

        //init the result string that will keep track of all previously called set values prior to timestamp
        //init w/ an empty string such that if the whole loop completes and the "" is the most recent -> no such val
        string valueBeforeTimestamp = "";

        //keep looping while left and right have not crossed over each other -> looking for a target val
        while(left <= right)
        {
            //calculate the middle in a way to prevent overflow
            int middle = (right - left) / 2 + left;

            //check if the middle index's timestamp = passed in timestamp -> if so return the val
            if(keyValueTime[middle].second <= timestamp)
            {
                //first append middle's value to the string vector
                valueBeforeTimestamp = keyValueTime[middle].first;

                //increase left to see if there is a more recent set for get to return
                left = middle + 1;
            }
            //otherwise check if the middle's timestamp is > timestamp -> if so decrease right
            else right = middle - 1;
        }

        //if the whole loop has completed -> assume there is no assoc val -> return ""
        return valueBeforeTimestamp;
    }
};
