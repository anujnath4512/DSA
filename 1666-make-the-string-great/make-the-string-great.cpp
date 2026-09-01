class Solution {
public:
    string makeGood(string s){
        stack<char>st;
        for(char ch:s){
            if(!st.empty() && tolower(ch)==tolower(st.top()) &&
            ch!=st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string ans;

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};