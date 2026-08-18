class Solution {
public:
stack<int> stk;
    int opr(int a, int b, string s){
        if(s == "+"){
            return a + b;
        }else if(s == "-"){
            return a - b;
        }else if(s == "*"){
            return a * b;
        }else{
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        string oprs = "+-*/";
        int val1, val2;
        for(int i=0; i<n; ++i){
            if(tokens[i].size() == 1 && oprs.find(tokens[i][0]) != string::npos){
                val2 = stk.top();stk.pop();
                val1 = stk.top();stk.pop();
                stk.push(opr(val1, val2, tokens[i]));
            }else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};