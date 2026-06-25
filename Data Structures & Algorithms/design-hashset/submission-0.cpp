class MyHashSet {
    vector<int> x;
public:
    MyHashSet() {
        vector<int> x;
    }
    
    void add(int key) {
        auto it = find(x.begin(),x.end(),key);
        if(it == x.end()){
            x.push_back(key);
        } 
    }
    
    void remove(int key) {
        auto it = find(x.begin(),x.end(),key);
        if(it!=x.end()){x.erase(it);}
    }
    
    bool contains(int key) {
        auto it = find(x.begin(),x.end(),key);
        if(it != x.end()){
            return true;
        }
        return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */