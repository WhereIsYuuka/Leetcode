class RandomizedSet {
public:
    unordered_map<int,int> idx;
    vector<int> num;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(idx.count(val) == 0)
        {
            idx[val] = num.size();
            num.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(idx.count(val))
        {
            int len = num[num.size() - 1];
            idx[len] = idx[val];
            swap(num[idx[val]], len);
            num.pop_back();
            idx.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int id = rand() % num.size();
        return num[id];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */