class Checkout {
    private:
        queue<int> que;
        deque<int> max_deq;
    
    public:
        Checkout() {
            
        }
        
        int get_max() {
            return max_deq.empty() ? -1 : max_deq.front();
        }
        
        void add(int value) {
            que.push(value);
            while(!max_deq.empty() && max_deq.back() < value)
            {
                max_deq.pop_back();
            }
            max_deq.push_back(value);
        }
        
        int remove() {
            if(que.empty())
                return -1;
            int tmp = que.front();
            que.pop();
            if(max_deq.front() == tmp)
                max_deq.pop_front();
            return tmp;
        }
    };
    
    /**
     * Your Checkout object will be instantiated and called as such:
     * Checkout* obj = new Checkout();
     * int param_1 = obj->get_max();
     * obj->add(value);
     * int param_3 = obj->remove();
     */