class TimeMap {
public:
unordered_map<string, vector<pair<string,int>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        int n = mp[key].size();
        int low = 0, high = n-1;
        int lowTimestamp = mp[key][0].second;
        int highTimestamp = mp[key][n-1].second;
        if(timestamp < lowTimestamp){
            return "";
        }
        if(timestamp > highTimestamp){
            return mp[key][n-1].first;
        }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(mp[key][mid].second == timestamp){
                return mp[key][mid].first;
            }else if(mp[key][mid].second <= timestamp){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return mp[key][high].first;

    }
};
