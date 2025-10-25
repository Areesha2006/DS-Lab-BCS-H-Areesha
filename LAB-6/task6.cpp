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
string infix_to_prefix(string infix){
    string prefix="";
    Stack stack(infix.length());
    for(int i=infix.length()-1;i>=0;i--){
        if(infix[i]>='0'&&infix[i]<='9'){
            prefix+=infix[i];
        }
        else if(infix[i]==')'){
            stack.push(infix[i]);
        }
        else if(infix[i]=='('){
            while(!stack.is_empty()&&stack.top!=')'){
                prefix+=stack.pop();
            }
            if(!stack.is_empty()){
                stack.pop();
            }
        }
        else{
            while(!stack.is_empty()&&precedence(infix[i])<=precedence(stack.top)){
                prefix+=stack.pop();
            }
            stack.push(infix[i]);
        }
    }
    while(!stack.is_empty()){
        prefix+=stack.pop();
    }
    int start=0,end=prefix.length()-1;
    while(start<end){
        char c=prefix[start];
        prefix[start]=prefix[end];
        prefix[end]=c;
        start++;
        end--;
    }
    return prefix;
}
int evaluate_prefix(string pre){
    Stack prefix(pre.length());
    for (int i = pre.length()-1; i >= 0; i--){
        if(pre[i]>='0'&&pre[i]<='9'){
            prefix.push(pre[i]-'0');
        }
        else{
            int a=prefix.top;
            prefix.pop();
            int b=prefix.top;
            prefix.pop();
            if(pre[i]=='+'){
                prefix.push(a+b);
            }
            else if(pre[i]=='-'){
                prefix.push(a-b);
            }
            else if(pre[i]=='*'){
                prefix.push(a*b);
            }
            else if(pre[i]=='/'){
                prefix.push(a/b);
            }
            else{
                prefix.push(pow(a,b));
            }
        }
    }
    return prefix.top;
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
        cout<<"Infix to prefix: "<<infix_to_prefix(infix)<<endl;
        cout<<"After evaluating the prefix the answer is "<<evaluate_prefix(infix_to_prefix(infix));
    }
    else{
        cout<<"The infix is not valid";
    }
    return 0;
}