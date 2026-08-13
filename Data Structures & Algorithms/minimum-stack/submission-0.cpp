class MinStack {
public:
     stack<int> s;
     stack<int> minstack;
    MinStack() {
    }
    
    void push(int val) {
       s.push(val);
       if(minstack.empty()){
         minstack.push(val);
       }
       else{
           minstack.push(min(minstack.top(),val));
       }
    }
    
    void pop() {
        s.pop();
        minstack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
