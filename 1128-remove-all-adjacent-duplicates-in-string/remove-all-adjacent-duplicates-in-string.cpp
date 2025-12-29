class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.size();

        stack<char>st;
        
        string res="";

        for(int i=0;i<n;i++){
            if(st.empty()==1){
                st.push(s[i]);
                continue;
            }
            if(st.top()==s[i]){
                st.pop();
                continue;
            }
            else{

                st.push(s[i]);
            }
        }

        while(st.empty()==0){
            res=res+st.top();
            st.pop();
        }

        reverse(res.begin(),res.end());

        return res;
    }
};