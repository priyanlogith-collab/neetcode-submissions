class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<int> stk;
        vector<int> ans(tem.size(),0);
        for(int i=0; i<tem.size(); ++i){
            while(!stk.empty() && tem[i] > tem[stk.top()]){
                int id = stk.top();
                ans[id] = i - id;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
