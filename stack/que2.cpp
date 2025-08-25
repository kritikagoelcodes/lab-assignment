#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse(string str){
    stack<char> st;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        st.push(ch);
    }

    string rev ="";
    while(!st.empty()){
        rev = rev + st.top();
        st.pop();
    }

    return rev;
}

int main(){
    string str = "DataStructure";
    string rev = reverse(str);

    cout<<"original string: "<< " "<<str <<endl;
    cout<<"reversed string: "<<" " <<rev <<endl;

    
}