class MyHashMap {
    vector<pair<int,int>> x;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto it = x.begin(); it!=x.end(); ++it){
            if(it->first == key){
                it->second = value;
                return ;
            }
        }
        x.push_back({key,value});
    }
    
    int get(int key) {
        for(auto it = x.begin(); it!=x.end(); ++it){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for(auto it = x.begin(); it!=x.end(); ++it){
            if(it->first == key){
                x.erase(it);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */