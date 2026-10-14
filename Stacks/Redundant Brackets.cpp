#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack <char> st;

    for(int i = 0; i < s.length(); i++){
        char ch = s[i];

        // when ch is any operator or '(' then push it in the stack  
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            // when ch is ')' or any lower case alphabet
            if(ch == ')'){

                bool isRedundant = true;
                
                while(st.top() != '('){
                    char top = st.top();
                  // if their is any operator between the brackets that means the stack is Non - Redundant 
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }

                if(isRedundant == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
