#include<iostream>
#include<math.h>
using namespace std;
class Stack{
    int length;
    string str;
    public:
        char top;
        Stack(int l){
            length=l;
            str="";
        }
        void push(char c){
            str+=c;
            top=c;
        }
        char pop(){
            char x=str[str.length()-1];
            str.resize(str.length()-1);
            if(is_empty()){
                top='\0';
            }
            else{
                top=str[str.length()-1];
            }
            return x;
        }
        bool is_empty(){
            return str=="";
        }
};
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infix_to_postfix(string infix){
    string postfix="";
    Stack stack(infix.length());
    for(int i=0;i<infix.length();i++){
        if(infix[i]>='0'&&infix[i]<='9'){
            postfix+=infix[i];
        }
        else if(infix[i]=='('){
            stack.push(infix[i]);
        }
        else if(infix[i]==')'){
            while(!stack.is_empty()&&stack.top!='('){
                postfix+=stack.pop();
            }
            if(!stack.is_empty()){
                stack.pop();
            }
        }
        else{
            while(!stack.is_empty()&&precedence(infix[i])<=precedence(stack.top)){
                postfix+=stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    while(!stack.is_empty()){
        postfix+=stack.pop();
    }
    return postfix;
}
int evaluate_postfix(string post){
    Stack postfix(post.length());
    for (int i = 0; i < post.length(); i++){
        if(post[i]>='0'&&post[i]<='9'){
            postfix.push(post[i]-'0');
        }
        else{
            int b=postfix.top;
            postfix.pop();
            int a=postfix.top;
            postfix.pop();
            if(post[i]=='+'){
                postfix.push(a+b);
            }
            else if(post[i]=='-'){
                postfix.push(a-b);
            }
            else if(post[i]=='*'){
                postfix.push(a*b);
            }
            else if(post[i]=='/'){
                postfix.push(a/b);
            }
            else{
                postfix.push(pow(a,b));
            }
        }
    }
    return postfix.top;
}
int main(){
    string infix;
    bool is_valid=true;
    cout<<"Enter infix that contains only digits, operators or brakets: ";
    cin>>infix;
    for (int i = 0; i < infix.length(); i++){
        if(!((infix[i]>='0'&&infix[i]<='9')||infix[i]=='('||infix[i]==')'||infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')){
            is_valid=false;
        }
    }
    if(is_valid){
        cout<<"Infix to postfix: "<<infix_to_postfix(infix)<<endl;
        cout<<"After evaluating the postfix the answer is "<<evaluate_postfix(infix_to_postfix(infix));
    }
    else{
        cout<<"The infix is not valid";
    }
    return 0;
}