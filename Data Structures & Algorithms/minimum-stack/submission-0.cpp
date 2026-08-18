class MinStack {
public:
stack<pair<int,int>> s;
    MinStack() {}
    
    void push(int value) {
        if(!s.empty()){
            s.push({value, min(value, s.top().second)});
        }else{
            s.push({value,value});
        }
    }
    
    void pop() {
        if(!s.empty()){
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
