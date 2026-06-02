class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //combine the position and speed vectors into a single vector
        vector<pair<int, int>> posSpeed;

        //loop through each index of both pos and speed
        for(int i = 0; i < position.size(); i++)
        {
            //append the pair of position and speed into posSpeed
            posSpeed.push_back({position[i], speed[i]});
        }


        //sort the posSpeed vector in desc order by the position it is
        sort(posSpeed.rbegin(), posSpeed.rend());

        //init a vector acting like a stack that will track the arrival time of each car
        vector<double> arrivals;

        //loop through each position
        for(const auto& pairs : posSpeed)
        {
            //calc that car's arrival time as the distance to target / speed and push onto stack
            arrivals.push_back((double)(target - pairs.first) / pairs.second);
            //check if arrTime is faster than the top element -> if it is then pop the elem since no new fleet is formed
            if(arrivals.size() >= 2 && arrivals.back() <= arrivals[arrivals.size() - 2]) arrivals.pop_back();
        }

        //return the # of fleets formed
        return arrivals.size();
    }
};
