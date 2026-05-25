class MinStack {
private:
    vector<int> mainStack;
    vector<int> minStack;

public:
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push_back(val);

        if (minStack.empty())
        {
            minStack.push_back(val);
        }
        else
        {
            minStack.push_back(min(val, minStack.back()));
        }
    }
    
    void pop() {
        if (!mainStack.empty()) 
        {
            mainStack.pop_back();
            minStack.pop_back();
        }
    }
    
    int top() {
        return mainStack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
