#include <iostream>

using namespace std;

void print(int *arr,int len){

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

void insertionSort(int *arr,int len){

    for(int i=1;i<=len-1;i++){
        int key =  arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j] > key){
                arr[j+1] = arr[j];
            }else{
                arr[j+1] = key;
                break;
            }
        }

    }

}


int main(){


    int arr[10] = {1,22,0,4,5,65,5,8,9,22};

    print(arr,10);
    insertionSort(arr,10);
    print(arr,10);



    return 0;
}