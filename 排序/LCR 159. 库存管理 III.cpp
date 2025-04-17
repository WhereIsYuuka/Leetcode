// class Solution {
//     public:
//         vector<int> inventoryManagement(vector<int>& stock, int cnt) {
//             priority_queue<int, vector<int>, greater<int>> pque;
//             vector<int> res;
//             for(auto num : stock)
//             {
//                 pque.emplace(num);
//             }
//             for(int i = 0; i < cnt; i++)
//             {
//                 res.emplace_back(pque.top());
//                 pque.pop();
//             }
//             return res;
//         }
//     };

class Solution {
    public:
        vector<int> inventoryManagement(vector<int>& stock, int cnt) {
            quick_sort(stock, 0, stock.size()-1);
            vector<int> res;
            res.assign(stock.begin(), stock.begin()+cnt);
            return res;
        }
    
        void quick_sort(vector<int>& stock, int l, int r)
        {
            if(l >= r)
                return;
            int i = l, j = r;
            while(i < j)
            {
                while(i < j && stock[j] >= stock[l])
                    j--;
                while(i < j && stock[i] <= stock[l])
                    i++;
                swap(stock[i], stock[j]);
            }
            swap(stock[i], stock[l]);
    
            quick_sort(stock, l, i-1);
            quick_sort(stock, i+1, r);
        }
    };