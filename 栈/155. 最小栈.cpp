class MinStack {
public:
    stack<pair<int, int>> sta;
    MinStack() {

    }
    
    void push(int val) {
        sta.push({val, min(val, getMin())});
    }
    
    void pop() {
        sta.pop();
    }
    
    int top() {
        return sta.top().first;
    }
    
    int getMin() {
        if(!sta.empty())
        {
            return sta.top().second;
        }
        return INT_MAX;
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

// class MinStack {
// public:
//     stack<pair<int, int>> sta;
//     MinStack() {

//     }
    
//     void push(int val) {
//         sta.push({val, min(val, getMin())});
//     }
    
//     void pop() {
//         sta.pop();
//     }
    
//     int top() {
//         return sta.top().first;
//     }
    
//     int getMin() {
//         if(!sta.empty())
//             return sta.top().second;
//         else
//             return INT_MAX;
//     }
// };
