 #include<iostream>
 using namespace std;
 void reverseString( string &str){
   int start=0,end=str.length()-1;
   while(start<=end){
     swap(str[start],str[end]);
    start++;
      end--;
   }
 }

int main(){
    string str;
    cout<<"Enter a string : ";
    getline(cin,str);

   reverseString(str);
   cout<<str;
return 0;
}