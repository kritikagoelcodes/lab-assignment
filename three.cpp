#include<iostream>
using namespace std;
int findMissing(int arr[],int size){
    int totalSum=size*(size+1)/2;
     int arraySum=0;
     for(int i=0;i<size-1;i++){
            arraySum=arraySum+arr[i];
     }
return totalSum-arraySum;
}

int main(){
    int arr[]={1,2,3,5,6};
    int size=6;
    int result=findMissing(arr,size);
    cout<<"Missing term is: "<< result;
    return 0;
    }