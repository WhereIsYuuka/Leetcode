class CQueue {
private:
    stack<int> stk1, stk2;

public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stk1.emplace(value);
    }
    
    int deleteHead() {
        if(!stk2.empty())
        {
            int tmp = stk2.top();
            stk2.pop();
            return tmp;
        }
        if(stk1.empty())
            return -1;
        while(!stk1.empty())
        {
            stk2.emplace(stk1.top());
            stk1.pop();
        }
        int tmp = stk2.top();
        stk2.pop();
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */