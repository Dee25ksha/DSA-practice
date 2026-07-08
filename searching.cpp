#include<iostream>
using namespace std;
void linear_serach(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            cout<<"Element found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found in the array"<<endl;
}

void binary_search(int arr_sorted[],int n,int key){

    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr_sorted[mid]==key){
            cout<<"Element found at index "<<mid<<endl;
            return;
        }
        else if(arr_sorted[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<"Element not found in the array"<<endl;
}

int main(){
    int arr[5]={34,56,32,78,12};
    int key=56;
    linear_serach(arr,5,key);
    int arr_sorted[5]={12,32,34,56,78};
    binary_search(arr_sorted,5,key);
}