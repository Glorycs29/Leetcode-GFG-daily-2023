//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    // create precedence function
    int prec(char c){
        if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else if(c=='^')return 3;
        else return -1;
    }
    

    string infixToPostfix(string s) {
        stack<int> st;
        string res;
        int n=s.length();
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c >= 'a' && c <= 'z' || c >='A' && c <='Z'){
                res+=c;
            }
            else if(c=='('){
                st.push(c);
            }else if(s[i]==')'){
                while(st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && (prec(c)<=prec(st.top()))){
                    res+=st.top();
                    st.pop();
                }
                st.push(c);
            }
            
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        
        
        
        
        
        
        return res;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
