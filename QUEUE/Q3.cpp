#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int>& q){
    int n = q.size();
    if(n%2!=0){
        cout<<"Queue has odd numbers, interleave cannot happen properly"<<endl;
        return;
    }

    int half = n/2;
    queue<int> firsthalf;

    for(int i = 0;i<half;i++){
        firsthalf.push(q.front());
        q.pop();
    }

    while(!firsthalf.empty()){
        q.push(firsthalf.front());
        firsthalf.pop();


        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleave(q);
    cout<<"Interleaved Queue: ";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

}