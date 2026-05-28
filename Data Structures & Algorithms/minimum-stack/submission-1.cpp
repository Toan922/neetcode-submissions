class MinStack {
//declare a priv class var representing the actual stack and the min stack
private:
    //realStack is the actual stack being interacted w/
    vector<int> realStack;
    //minStack is used to keep track of the current min val for getMin
    vector<int> minStack;

public:
    //constructor should remain empty as the stacks only need to be init
    MinStack() {
    }
    
    //realStack gets whatever val is pushed onto it whereas minStack needs to check if it is < curr top
    void push(int val) {
        realStack.push_back(val);

        //if minStack is empty then push val onto it
        if(minStack.empty()) minStack.push_back(val);
        //otherwise push the minimum between val and the top of the minStack
        else minStack.push_back(min(val, minStack.back()));
    }
    
    void pop() {
        //pop from both stacks if realStack is not empty
        if(!realStack.empty())
        {
            realStack.pop_back();
            minStack.pop_back();
        }
    }
    
    //looking at just the top val of realStack
    int top() {
        return realStack.back();
    }
    
    //minStack's top val is the minimum val in realStack -> look at minStack's top
    int getMin() {
        return minStack.back();
    }
};
