class RandomizedSet {
public:
    unordered_set<int> stt;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(stt.count(val))  return 0;
        stt.insert(val);
        return 1;        
    }
    
    bool remove(int val) {
        if(!stt.count(val))  return 0;
        stt.erase(val);
        return 1;
    }
    
    int getRandom() {
        int n = stt.size();
        int r = rand()%n;

        auto itr = stt.begin();

        advance(itr,r);

        return *itr;

        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
