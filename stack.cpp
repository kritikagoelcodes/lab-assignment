#include<iostream>

using namespace std;

class Stack{

    public:
    int *arr;
    int top=-1;
    int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"stack overflow";
        }
    }

    void pop(){
        if(top>=0){
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
        else{
            cout<<"Stack Underflow";
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Empty Stack";
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top==size-1){
            return true;
        }
        else{
            return false;
        }
    }

     void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Stack elements (Top to Bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    int choice;
    Stack st(5);
    do{
        cout<<"\n----Stack Menu----\n";
        cout<< "1. Push \n";
        cout<< "2. pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout<< "5. Display\n";
        cout<< "6. peek\n";
        cout << "7. Exit\n";

        
    
        
    
        cout<<"Enter your choice: ";
        cin>>choice;
       

if (cin.fail()) {
    cin.clear();              
    cin.ignore(1000, '\n');  
    choice = -1;             
}

        switch(choice){
            case 1: {
            cout<<"Enter element to push: ";
            int element;
            cin >> element;
            st.push(element);
            break;
            }
            case 2:
            st.pop();
            break;
            case 3:
             if (st.isEmpty())
                    cout << "Stack is Empty." << endl;
            else
                    cout << "Stack is NOT Empty." << endl;
            break;
            case 4:
            if (st.isFull())
                    cout << "Stack is Full." << endl;
            else
                    cout << "Stack is NOT Full." << endl;
             break;
             
             case 5:
                st.display();
                break;
             

             case 6:
                cout << "Top element: " << st.peek() << endl;
                break;
             case 7:
            cout << "Exiting program..." << endl;
            break;
            
    
        
        }
    } while(choice != 7);
    return 0;
}









        
       
        

        
    
    


