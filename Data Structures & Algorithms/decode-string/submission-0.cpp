class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string substr;
        for(int i=0;i<s.size();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            }
            else{
                substr="";
                while(st.top()!='['){
                    substr+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(substr.begin(),substr.end());
                string k="";
                while(!st.empty()&&(st.top()>='0'&&st.top()<='9')){
                    k+=st.top();
                    st.pop();
                }
                reverse(k.begin(), k.end());
                int num = stoi(k);
                string temp = substr;
                substr = ""; 
                for(int j=0;j<num;j++){
                   substr += temp;
                  } 
                for(char c:substr){
                    st.push(c);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};