class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //create the stack for holding prev temps to compare to
        stack<int> prevTemps;

        //create the vector to be returned
        vector<int> daysBefore(temperatures.size(), 0);

        //loop through temps
        for(int i = 0; i < temperatures.size(); i++)
        {
            //while stack is not empty and curr temp > prev temps -> pop the top temp and calc index diff
            while(!prevTemps.empty() && temperatures[i] > temperatures[prevTemps.top()])
            {
                //store the prev temp's index into a temp var
                int prev = prevTemps.top();
                
                //pop the top elem of the stack
                prevTemps.pop();

                //store the difference of i and prev index into the index of daysBefore
                daysBefore[prev] = i - prev;
            }

            //push the current index onto the stack
            prevTemps.push(i);
        }

        //return daysBefore
        return daysBefore;
    }
};
