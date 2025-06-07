#include <vector>

class MinStack {
public:
    std::vector<int> stack;
    std::vector<int> minstack;

    MinStack() {
    }
    
    void push(int val) {
        /* If stack is empty (first push) or if new value is lesser than 
           the current minimum, then push new value in minstack */
        if(stack.empty() || val <= minstack.back()) {
            minstack.push_back(val);
        }
        /* else includes the case when the new value to be pushed is 
           larger than the current minimum, then just re-push the 
           current minimum again */
        else {
            minstack.push_back(minstack.back());
        }
        stack.push_back(val);
    }
    
    void pop() {
        stack.pop_back();
        minstack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minstack.back();        
    }

};