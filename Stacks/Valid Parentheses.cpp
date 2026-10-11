bool isValidParenthesis(string s)
{
    stack<char> exp;

    for(int i=0; i < s.length(); i++){

        char ch = s[i];

        // for opening bracket push in stack 
        if(ch == '(' || ch == '{' || ch == '['){
            exp.push(ch);
        }
        // for closing bracket check top of stack and remove the top if matches 
        else{
            // atleast one element in a stack
            if(!exp.empty()){
                char top = exp.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                    exp.pop();
                }
                // brackets doesn't matches 
                else{
                    return false;
                }
            }
            // empty stack
            else {
                return false;
            }
        }   
    }
    if(exp.empty()){
        return true;
    }
    else{
        return false;
    }
}
