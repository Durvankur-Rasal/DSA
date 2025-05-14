#include <iostream>
#include <stack>

using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void infixToPostfix(string exp){
    
    stack<char> st;
    string result = "";

    for (int i=0; i< exp.length(); i++){
         char c = exp[i];

         if((c  >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') ){
             result += c;
         }

        else if (c == ')'){
             while(c != '('){
                 result += st.top();
                    st.pop();
             }
             st.pop();
        }

        else {

            if(precedence(c) < precedence(st.top()) && st.size() != 0){ 
                    
                result += st.top();
                st.pop();
            }

            else{
                st.push(c);
            }
        }

        
    }

    while(st.size() != 0){
        result += st.top();
        st.pop();
    }

}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp);

  return 0;
}