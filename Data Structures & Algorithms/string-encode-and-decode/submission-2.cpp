class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i=0; i<strs.size(); ++i){
            ans += to_string(strs[i].size()) + '#' + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i < s.size()){
            // j is for figurating out the size of the string 
            int j=i;
            while(s[j] != '#'){
                j++;
            }
            // we gonna use the stl substr() for stiping out the size 
            int len = stoi(s.substr(i,j-i));

            i=j;

            string word ;
            word = s.substr(i+1,len);
            ans.push_back(word);
            i+=len+1;
        }
        return ans;
    }
};
