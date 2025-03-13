class MedianFinder {
    private:
        priority_queue<int, vector<int>, greater<int>> big; //大顶堆
        priority_queue<int, vector<int>, less<int>> small;  //小顶堆
    
    public:
        /** initialize your data structure here. */
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            if(big.size() != small.size())
            {
                big.push(num);
                small.push(big.top());
                big.pop();
            }
            else
            {
                small.push(num);
                big.push(small.top());
                small.pop();
            }
        }
        
        double findMedian() {
            return big.size() != small.size() ? big.top() : (small.top() + big.top()) / 2.0;
        }
    };
    
    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */