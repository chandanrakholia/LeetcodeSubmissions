// https://leetcode.com/problems/min-stack

class MinStack {
public:
    int MIN(stack<int>s){
        int m=0;
        for(int i=0;i<s.size();i++){
            if(s.top()<m){
                m=s.top();
                s.pop();
            }
            else{
                s.pop();
            }
        }
        return m;
    }
    stack<int>x;
    stack<int>min;
    MinStack() {

    }
    
    void push(int val) {
        if(x.size()==0 or min.top()>val){
            min.push(val);
        }
        x.push(val);
    }
    
    void pop() {
        if(min.top()==x.top())
        {
            min.pop();
            }
        x.pop();
            
    }
    
    int top() {
        return x.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */