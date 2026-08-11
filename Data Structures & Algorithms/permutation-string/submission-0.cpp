class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1;
        for(auto x : s1){
            mp1[x]++;
        }
        unordered_map<char, int> mp2;
        int left=0;
        for(int right=0; right < s2.size(); right++){
            mp2[s2[right]]++;
            if(right - left + 1 == s1.size()){
                if(mp1 == mp2){
                    return true;
                }
                mp2[s2[left]]--;
                if(mp2[s2[left]] == 0){mp2.erase(s2[left]);}
                left++;
            }
        }
        return false;
    }
};
