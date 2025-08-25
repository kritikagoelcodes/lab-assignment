#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i = 0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }

            if((st.top()=='(' && s[i]==')') ||
            (st.top()=='{' && s[i]=='}') ||
            (st.top()=='[' && s[i]==']')){
                st.pop();
            }  else {
                return false;
            }
        }
    }
return st.empty();
}


int main(){
    string s;
    cout<<"Enter parantheses string: ";
    cin>>s;


     if (isValid(s))
        cout<<"Valid\n";

        else
        cout<<"not valid";
    }
