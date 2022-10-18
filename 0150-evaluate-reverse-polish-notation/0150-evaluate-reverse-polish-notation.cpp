class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(string s: tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                auto num1 = st.top();st.pop();
                auto num2 = st.top();st.pop();
                if(s=="+")st.push(num1+num2);
                if(s=="-")st.push(num2-num1);
                if(s=="*")st.push(num1*num2);
                if(s=="/")st.push(num2/num1);
            }
            else{              
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};