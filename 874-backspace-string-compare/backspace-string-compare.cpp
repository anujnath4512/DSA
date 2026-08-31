class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(char ch:s){
            if(ch=='#'){
                if(!st1.empty()){
                    st1.pop();
                }
            }
            else{
                st1.push(ch);
            }
        }

        for(char ch:t){
            if(ch=='#'){
                if(!st2.empty()){
                    st2.pop();
                }
            }
            else{
                st2.push(ch);
            }
        }

        string a = "";
        string b = "";

        while(!st1.empty()) {
            a += st1.top();
            st1.pop();
        }

        while(!st2.empty()) {
            b += st2.top();
            st2.pop();
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        return a == b;
    }
};