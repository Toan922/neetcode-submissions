class MinStack {
private:
    //keep the data types private for both the normal stack and the min stack
    vector<int> normalstack;
    vector<int> minstack;
public:
    MinStack() {
        //remains empty to serve as an init for constructor
    }
    
    void push(int val) {
        //always push to the normal stack
        normalstack.push_back(val);

        //if minstack is empty -> push onto minstack
        if(minstack.empty()) minstack.push_back(val);
        //otherwise if curr val is < curr min -> push onto minstack
        else minstack.push_back(min(val, minstack.back()));
    }
    
    void pop() {
        if(!normalstack.empty())
        {
            normalstack.pop_back();
            minstack.pop_back();
        }
    }
    
    int top() {
        return normalstack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};
