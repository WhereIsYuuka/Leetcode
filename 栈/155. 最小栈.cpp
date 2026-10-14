class MinStack {
    stack<pair<int, int>> minStk;
public:
    MinStack() {
        minStk.push({0, INT_MAX});
    }
    
    void push(int value) {
        minStk.push({value, min(getMin(), value)});
    }
    
    void pop() {
        minStk.pop();
    }
    
    int top() {
        return minStk.top().first;
    }
    
    int getMin() {
        return minStk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
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
//         {
//             return sta.top().second;
//         }
//         return INT_MAX;
//     }
// };



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

// class MinStack {
// public:
//     stack<pair<int, int>> stk;
//     MinStack() {
//         stk.emplace(0, INT_MAX);
//     }
    
//     void push(int val) {
//         stk.emplace(val, min(getMin(), val));
//     }
    
//     void pop() {
//         stk.pop();
//     }
    
//     int top() {
//         return stk.top().first;
//     }
    
//     int getMin() {
//         return stk.top().second;
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */